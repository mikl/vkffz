<?php
/**
 * @file
 * Migrate API code for the VKFFZ migrate module.
 */

/**
 * Implements hook_migrate_api().
 */
function vkffz_migrate_migrate_api() {
  $api = [
    'api' => 2,

    'groups' => [
      'vkffz' => [
        'title' => t('VKFFZ Imports'),
      ],
    ],

    'migrations' => [
      'VkffzIncident' => [
        'class_name' => 'VkffzIncidentMigration',
        'group_name' => 'vkffz',
      ],
      'VkffzNewsVerein' => [
        'class_name' => 'VkffzNewsVereinMigration',
        'group_name' => 'vkffz',
      ],
    ],
  ];

  return $api;
}
