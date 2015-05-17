<?php

/**
 * @file
 * Class VkffzNewsMigration
 */
abstract class VkffzNewsMigration extends VkffzBaseMigration {

  const CATEGORY_ID = -1;

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('VKFFZ news');
    $this->dependencies = array();

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

    $query = Database::getConnection('default', 'for_migration')
      ->select('jos_content', 'jt')
      ->fields('jt', array('id', 'asset_id', 'title', 'alias', 'introtext',
        'state', 'sectionid', 'catid', 'created', 'modified', 'attribs'))
      // Filter by the categories for the news.
      ->condition('catid', $this::CATEGORY_ID)
    ;

    // Workaround for Joomla! using a MySQL reserved word as a column name. Brilliant.
    $query->addField('jt', 'fulltext', 'fulljoomlatext');

    $count_query = Database::getConnection('default', 'for_migration')
      ->select('jos_content', 'jt')
      ->condition('catid', $this::CATEGORY_ID)
    ;

    $count_query->addExpression('COUNT(id)', 'jt');

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

    $this->source = new MigrateSourceSQL($query, $source_fields, $count_query);
    $this->destination = new MigrateDestinationNode('fuur_news');

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
    $this->addFieldMapping('fuur_base_body:format')->defaultValue('fuur_wysiwyg');

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

    $current_row->title = self::vkffzStripDateFromTitle($current_row->title);

    // Set the published status, defaults to 1.
    $current_row->published = 1;

    // Merge the intro text and the full text into the new body.
    $current_row->body_text = $current_row->introtext . "\r\r" . $current_row->fulljoomlatext;

    return TRUE;
  }

  /**
   * Remove date from the title, if present.
   *
   * @param string $title
   *
   * @return string
   */
  public static function vkffzStripDateFromTitle($title) {
    return preg_replace('/^(\s*\d{1,2}\.\d{1,2}\.\d{2})\s*/', '', $title);
  }

}
