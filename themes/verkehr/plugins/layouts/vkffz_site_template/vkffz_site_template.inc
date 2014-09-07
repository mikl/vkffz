<?php
/**
 * @file
 * Definition of MGB site template layout.
 */

$plugin = array(
  'title' => t('Site template'),
  'theme' => 'vkffz-site-template',
  'icon' => 'vkffz-site-template.png',
  'css' => 'vkffz-site-template.css',
  'category' => 'VKFFZ',
  'regions' => array(
    'header' => t('Header'),
    'content' => t('Content'),
    'sidebar' => t('Sidebar'),
    'footer' => t('Footer'),
    'closure' => t('Closure'),
  ),
);