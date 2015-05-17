<?php

/**
 * @file
 * Class VkffzNewsMigration
 */
class VkffzNewsVereinMigration extends VkffzNewsMigration {

  /**
   * {@inheritdoc}
   */
  const SOURCE_CATEGORY_ID = 3;

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('VKFFZ news (verein)');
  }
}
