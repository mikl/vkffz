<?php

/**
 * @file
 * Class VkffzNewsVereinMigration
 */
class VkffzNewsVereinMigration extends VkffzNewsMigration {

  /**
   * {@inheritdoc}
   */
  const SOURCE_CATEGORY_ID = 3;

  /**
   * {@inheritdoc}
   */
  const DESTINATION_CATEGORY = 'Verein';

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('VKFFZ news (verein)');
  }
}
