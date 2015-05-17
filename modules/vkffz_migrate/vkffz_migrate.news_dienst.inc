<?php

/**
 * @file
 * Class VkffzNewsDienstMigration
 */
class VkffzNewsDienstMigration extends VkffzNewsMigration {

  /**
   * {@inheritdoc}
   */
  const SOURCE_CATEGORY_ID = 43;

  /**
   * {@inheritdoc}
   */
  const DESTINATION_CATEGORY = 'Dienst';

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('VKFFZ news (dienst)');
  }
}
