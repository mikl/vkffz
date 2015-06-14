<?php
/**
 * @file
 * Definition of MGB site template layout.
 */

$plugin = array(
  'title' => t('Site template'),
  'theme' => 'vkffz_site_template',
  'icon' => 'vkffz-site-template.png',
  'css' => 'vkffz-site-template.css',
  'category' => 'VKFFZ',
  'regions' => array(
    'header' => t('Header'),
    'subnav' => t('Sub-navigation'),
    'content' => t('Content'),
    'sidebar' => t('Sidebar'),
    'footer' => t('Footer'),
    'closure' => t('Closure'),
  ),
);
