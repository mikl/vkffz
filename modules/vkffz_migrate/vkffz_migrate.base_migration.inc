<?php
/**
 * @file
 * VkffzBaseMigration class definition
 */

/**
 * Class VkffzBaseMigration
 *
 * Base class for our other Migrations.
 */
abstract class VkffzBaseMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->team = [
      new MigrateTeamMember('Mikkel Høgh', 'mikkel@hoegh.org',
        t('Implementor')),
    ];

    // Standard pattern.
    $this->issuePattern = 'http://drupal.org/node/:id:';
  }
}
