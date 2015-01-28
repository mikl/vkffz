<?php
/**
 * @file
 * Migrations for the vkffz_migrate module.
 */

class VkffzIncidentMigration extends VkffzBaseMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('VKFFZ incidents');
    $this->dependencies = array();

    // You can add a 'track_last_imported' option to the map, to record the
    // timestamp of when each item was last imported in the map table.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Content ID',
          'alias' => 'jt',
        )
      ),
      MigrateDestinationNode::getKeySchema(),
      'for_migration', // Use the migration database, not Drupal's.
      array('track_last_imported' => TRUE)
    );

    //SELECT * FROM jos_content WHERE sectionid = 91 AND catid IN (60, 87, 88, 89, 90, 180, 181, 182)

    $query = Database::getConnection('default', 'for_migration')
      ->select('jos_content', 'jt')
      ->fields('jt', array('id', 'asset_id', 'title', 'alias', 'introtext',
        'state', 'sectionid', 'catid', 'created', 'modified', 'attribs'))
      // Filter by the categories for the incidents.
      ->condition('catid', array(60, 87, 88, 89, 90, 180, 181, 182), 'IN')
    ;

    // Workaround for Joomla! using a MySQL reserved word as a column name. Brilliant.
    $query->addField('jt', 'fulltext', 'fulljoomlatext');

    $count_query = Database::getConnection('default', 'for_migration')
      ->select('jos_content', 'jt')
      ->condition('catid', array(60, 87, 88, 89, 90, 180, 181, 182), 'IN')
    ;

    // TIP: By passing an array of source fields to the MigrateSourceSQL constructor,
    // we can modify the descriptions of source fields (which just default, for
    // SQL migrations, to table_alias.column_name), as well as add additional fields
    // (which may be populated in prepareRow()).
    $source_fields = [
      'id' => t('Content ID in the old system'),
      'title' => t('Title of the incident'),
    ];

    // TIP: By default, each time a migration is run, any previously unimported source items
    // are imported (along with any previously-imported items marked for update). If the
    // source data contains a timestamp that is set to the creation time of each new item,
    // as well as set to the update time for any existing items that are updated, then
    // you can have those updated items automatically reimported by setting the field as
    // your highwater field.
    $this->highwaterField = [
      'name' => 'modified', // Column to be used as highwater mark
      'alias' => 'jt',       // Table alias containing that column
      'type' => 'datetime', // By default, highwater marks are assumed to be lexicographically
      // sortable (e.g., '2011-05-19 17:53:12'). To properly
      // deal with integer highwater marks (such as UNIX
      // timestamps), indicate so here.
    ];

    // Note that it is important to process rows in the order of the highwater mark
    $query->orderBy('modified');

    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationNode('fuur_incident');

    // Mapped fields
    $this->addFieldMapping('title', 'title')
      ->description(t('Mapping content name in source to node title'));

    // These are already UNIX timestamps, so just pass through
    $this->addFieldMapping('created', 'conv_created');
    $this->addFieldMapping('changed', 'conv_changed');

    // All imported content will be in German.
    $this->addFieldMapping('language')->defaultValue('de');

    // All imported content will be considered to be authored by anonymous.
    $this->addFieldMapping('uid')->defaultValue(0);

    // Map published state of the imported row.
    $this->addFieldMapping('status', 'published');

    // Map body text into the body field.
    $this->addFieldMapping('fuur_base_body', 'body_text');

    // Map the incident timestamp to its field.
    $this->addFieldMapping('fuur_incident_datetime', 'incident_timestamp');

    // Unmapped destination fields.
    $this->addUnmigratedDestinations(['revision_uid', 'promote', 'revision', 'log', 'tnid', 'is_new']);
  }

  /**
   * Prepare a data row before it goes through the mapping process.
   *
   * @param $current_row
   * @return bool
   */
  public function prepareRow($current_row) {
    // Convert datetime timestamps to unix timestamps.
    $current_row->conv_created = MigrationBase::timestamp($current_row->created);
    $current_row->conv_changed = MigrationBase::timestamp($current_row->modified);

    // If changed timestamp is before the Unix epoch, set it to be the same as created timestamp.
    if ($current_row->conv_changed < 0) {
      $current_row->conv_changed = $current_row->conv_created;
    }

    // Set the published status, defaults to 1.
    $current_row->published = 1;

    // Try to find the date from the title.
    $incident_timestamp = self::vkffzExtractDateFromTitle($current_row->title);

    // Try to find the date from the intro text.
    if (!$incident_timestamp) {
      $incident_timestamp = self::vkffzExtractDate($current_row->introtext);
    }

    // Convert the incident timestamp to Unix time.
    if ($incident_timestamp instanceof DateTime) {
      $current_row->incident_timestamp = $incident_timestamp->getTimestamp();
    }
    // Unpublish nodes without a valid timestamp and report the error.
    else {
      $current_row->published = 0;

      $this->queueMessage('Failed to find incident date from record.');
    }

    // Merge the intro text and the full text into the new body.
    $current_row->body_text = $current_row->introtext . "\r\r" . $current_row->fulljoomlatext;

    return TRUE;
  }

  /**
   * Try to parse (and remove) date from title.
   *
   * @param string $title
   *
   * @return DateTime|null
   */
  public static function vkffzExtractDateFromTitle(&$title) {
    $matches = array();

    if (preg_match('/^(\d{1,2})\.(\d{1,2})\.(\d{2})\s*(.*)$/', trim($title), $matches)) {
      echo('Found timestamp from title: ' . $title);
      $title = $matches[4];

      $timestamp = new DateTime();
      $timestamp->setDate('20' . $matches[3], $matches[2], $matches[1]);


      return $timestamp;
    }
  }

  /**
   * Helper function to extract date from text string.
   *
   * @param string $input
   *   String to try and find date in.
   *
   * @return DateTime|null
   *   DateTime object if successful.
   */
  public static function vkffzExtractDate($input) {
    $matches = array();
    $timestamp = null;

    // 28. Februar 2013 or the like.
    if (preg_match('/(\d{1,2})\.\s{1,3}(\w{3,10})\s{1,3}(\d{4})/i', drupal_strtolower($input), $matches)) {
      $month = self::vkffzParseMonthText($matches[2]);

      if ($month) {
        $timestamp = new DateTime();
        $timestamp->setDate($matches[3], $month, $matches[1]);
      }
    }

    return $timestamp;
  }

  /**
   * Try to parse Swiss month names.
   *
   * @param string $input
   *   String to try and parse as a month.
   * @throws Exception
   *
   * @return int Month number.
   *   Month number.
   */
  public static function vkffzParseMonthText($input) {
    $input = trim(drupal_strtolower($input));

    switch ($input) {
      case 'januar':
        return 1;
      case 'februar':
        return 2;
      case 'märz':
        return 3;
      case 'april':
        return 4;
      case 'mai':
        return 5;
      case 'juni':
        return 6;
      case 'juli':
        return 7;
      case 'august':
        return 8;
      case 'september':
        return 9;
      case 'oktober':
        return 10;
      case 'november':
        return 11;
      case 'dezember':
        return 12;
      default:
        throw new Exception('Failed to parse month string: ' . $input);
    }
  }
}
