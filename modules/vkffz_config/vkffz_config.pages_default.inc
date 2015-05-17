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
    $pane->pid = 'new-815e66ec-5daa-46a0-92fa-fa96962c7902';
    $pane->panel = 'footer';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Contact info',
      'title' => '',
      'body' => '<p class="h-card">
  <a class="p-name u-url" href="http://www.vkffz.ch">Verkehrskorps der FFZ </a><br />

  <span class="p-street-address">Ahornstrasse 10</span><br />
  <span class="p-postal-code">CH-6301</span> <span class="p-locality">Zug</span><br />
  <span class="p-country-name">Schweiz</span><br />
  <br />
  <a class="u-email" href="mailto:info@vkffz.ch">info@vkffz.ch</a>
</p>',
      'format' => 'fuur_wysiwyg',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'contact-info',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '815e66ec-5daa-46a0-92fa-fa96962c7902';
    $display->content['new-815e66ec-5daa-46a0-92fa-fa96962c7902'] = $pane;
    $display->panels['footer'][0] = 'new-815e66ec-5daa-46a0-92fa-fa96962c7902';
    $pane = new stdClass();
    $pane->pid = 'new-485da3e1-5a57-4cc2-a793-c487b7fd204c';
    $pane->panel = 'footer';
    $pane->type = 'menu_tree';
    $pane->subtype = 'menu-secondary-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'menu_name' => 'menu-secondary-menu',
      'parent_mlid' => 0,
      'parent' => 'menu-secondary-menu:0',
      'title_link' => 0,
      'admin_title' => '',
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
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '485da3e1-5a57-4cc2-a793-c487b7fd204c';
    $display->content['new-485da3e1-5a57-4cc2-a793-c487b7fd204c'] = $pane;
    $display->panels['footer'][1] = 'new-485da3e1-5a57-4cc2-a793-c487b7fd204c';
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
    $pane->pid = 'new-24eb74bc-95f5-4882-bf06-9720ccdd726e';
    $pane->panel = 'sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'fuur_news_list-news_by_category_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '5',
      'offset' => '0',
      'context' => array(
        0 => 'empty',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '24eb74bc-95f5-4882-bf06-9720ccdd726e';
    $display->content['new-24eb74bc-95f5-4882-bf06-9720ccdd726e'] = $pane;
    $display->panels['sidebar'][1] = 'new-24eb74bc-95f5-4882-bf06-9720ccdd726e';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ed8e23e9-7dc8-4d34-b58a-f97afbec6872';
    $display->content['new-ed8e23e9-7dc8-4d34-b58a-f97afbec6872'] = $pane;
    $display->panels['sidebar'][2] = 'new-ed8e23e9-7dc8-4d34-b58a-f97afbec6872';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-69f5b37b-6fa3-4d33-a953-4e753579ed44';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  return $export;
}
