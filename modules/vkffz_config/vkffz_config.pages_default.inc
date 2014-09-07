<?php
/**
 * @file
 * vkffz_config.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function vkffz_config_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'VKFFZ default layout',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'vkffz-default-page',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'vkffz_site_template';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'first' => NULL,
      'second' => NULL,
      'third' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
      'closure' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '494faa3c-a7c4-46df-9efe-eb43eb0d7ad9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d2c24167-93dd-49ab-ac05-7c956c91c376';
    $pane->panel = 'content';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd2c24167-93dd-49ab-ac05-7c956c91c376';
    $display->content['new-d2c24167-93dd-49ab-ac05-7c956c91c376'] = $pane;
    $display->panels['content'][0] = 'new-d2c24167-93dd-49ab-ac05-7c956c91c376';
    $pane = new stdClass();
    $pane->pid = 'new-abf8600f-3a0b-424a-8411-f56da947fcea';
    $pane->panel = 'content';
    $pane->type = 'pane_messages';
    $pane->subtype = 'pane_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'abf8600f-3a0b-424a-8411-f56da947fcea';
    $display->content['new-abf8600f-3a0b-424a-8411-f56da947fcea'] = $pane;
    $display->panels['content'][1] = 'new-abf8600f-3a0b-424a-8411-f56da947fcea';
    $pane = new stdClass();
    $pane->pid = 'new-69f5b37b-6fa3-4d33-a953-4e753579ed44';
    $pane->panel = 'content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '69f5b37b-6fa3-4d33-a953-4e753579ed44';
    $display->content['new-69f5b37b-6fa3-4d33-a953-4e753579ed44'] = $pane;
    $display->panels['content'][2] = 'new-69f5b37b-6fa3-4d33-a953-4e753579ed44';
    $pane = new stdClass();
    $pane->pid = 'new-b9acc7bf-a23f-4f22-899c-39c655e191eb';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'system-powered-by';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b9acc7bf-a23f-4f22-899c-39c655e191eb';
    $display->content['new-b9acc7bf-a23f-4f22-899c-39c655e191eb'] = $pane;
    $display->panels['footer'][0] = 'new-b9acc7bf-a23f-4f22-899c-39c655e191eb';
    $pane = new stdClass();
    $pane->pid = 'new-37fec951-2f1b-4b0b-a1ad-b2e950089ea4';
    $pane->panel = 'header';
    $pane->type = 'pane_header';
    $pane->subtype = 'pane_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '37fec951-2f1b-4b0b-a1ad-b2e950089ea4';
    $display->content['new-37fec951-2f1b-4b0b-a1ad-b2e950089ea4'] = $pane;
    $display->panels['header'][0] = 'new-37fec951-2f1b-4b0b-a1ad-b2e950089ea4';
    $pane = new stdClass();
    $pane->pid = 'new-3046ea5b-9596-4300-bb28-700625351c2e';
    $pane->panel = 'header';
    $pane->type = 'menu_tree';
    $pane->subtype = 'main-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'menu_name' => 'main-menu',
      'parent_mlid' => 0,
      'parent' => 'main-menu:0',
      'title_link' => 0,
      'admin_title' => 'Main menu, level 1',
      'level' => '1',
      'follow' => 0,
      'depth' => '1',
      'expanded' => 0,
      'sort' => 0,
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3046ea5b-9596-4300-bb28-700625351c2e';
    $display->content['new-3046ea5b-9596-4300-bb28-700625351c2e'] = $pane;
    $display->panels['header'][1] = 'new-3046ea5b-9596-4300-bb28-700625351c2e';
    $pane = new stdClass();
    $pane->pid = 'new-e98f6a52-790a-4ca1-9ca1-dc94d68877bf';
    $pane->panel = 'sidebar';
    $pane->type = 'menu_tree';
    $pane->subtype = 'main-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'menu_name' => 'main-menu',
      'parent_mlid' => 0,
      'parent' => 'main-menu:0',
      'title_link' => 0,
      'admin_title' => 'Main menu, level 2+',
      'level' => '2',
      'follow' => 0,
      'depth' => '0',
      'expanded' => 0,
      'sort' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e98f6a52-790a-4ca1-9ca1-dc94d68877bf';
    $display->content['new-e98f6a52-790a-4ca1-9ca1-dc94d68877bf'] = $pane;
    $display->panels['sidebar'][0] = 'new-e98f6a52-790a-4ca1-9ca1-dc94d68877bf';
    $pane = new stdClass();
    $pane->pid = 'new-ed8e23e9-7dc8-4d34-b58a-f97afbec6872';
    $pane->panel = 'sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'fuur_sponsor_list-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '2',
      'offset' => '0',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '1800',
        'granularity' => 'none',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ed8e23e9-7dc8-4d34-b58a-f97afbec6872';
    $display->content['new-ed8e23e9-7dc8-4d34-b58a-f97afbec6872'] = $pane;
    $display->panels['sidebar'][1] = 'new-ed8e23e9-7dc8-4d34-b58a-f97afbec6872';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-69f5b37b-6fa3-4d33-a953-4e753579ed44';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  return $export;
}