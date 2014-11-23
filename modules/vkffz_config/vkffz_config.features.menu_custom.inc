<?php
/**
 * @file
 * vkffz_config.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function vkffz_config_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-secondary-menu.
  $menus['menu-secondary-menu'] = array(
    'menu_name' => 'menu-secondary-menu',
    'title' => 'Secondary menu',
    'description' => 'Menu links for the footer.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Menu links for the footer.');
  t('Secondary menu');


  return $menus;
}
