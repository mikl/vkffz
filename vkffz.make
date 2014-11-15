; This file was auto-generated by drush make
core = 7.x

api = 2
projects[drupal][version] = "7.33"
projects[drupal][patches][] = https://www.drupal.org/files/issues/1393094-remove-field-prefix-D7_1.patch

; Modules
projects[admin_menu][version] = "3.0-rc4"

projects[borealis][version] = "2.2"

projects[ctools][version] = "1.4"

projects[cache_actions][version] = "2.0-alpha5"

projects[date][version] = "2.8"

projects[diff][version] = "3.2"

projects[elements][version] = "1.4"

projects[entity][version] = "1.5"

projects[entitycache][version] = "1.2"

projects[features][version] = "2.2"

projects[fences][version] = "1.0"

projects[field_collection][version] = "1.0-beta7"

projects[field_formatter_settings][version] = "1.1"

projects[file_entity][version] = "2.0-beta1"

projects[fuur][type] = module
projects[fuur][download][type] = git
projects[fuur][download][url] = https://github.com/mikl/fuur.git
projects[fuur][download][revision] = f1b9c16

projects[genpass][version] = "1.0"

projects[html5_tools][version] = "1.2"

projects[panels][version] = "3.4"

projects[image_resize_filter][version] = "1.14"

projects[jquery_update][version] = "2.4"

projects[l10n_update][version] = "2.0-rc2"

projects[link][version] = "1.2"

projects[magic][version] = "1.5"

projects[media][version] = "2.0-alpha4"

projects[menu_block][version] = "2.4"

projects[module_filter][version] = "1.8"

projects[panels_everywhere][version] = "1.0-rc1"

projects[pathauto][version] = "1.2"

projects[redirect][version] = "1.0-rc1"

projects[redis][version] = "2.11"

projects[rules][version] = "2.7"

projects[strongarm][version] = "2.0"

projects[token][version] = "1.5"

projects[transliteration][version] = "3.2"

projects[views][version] = "3.8"

projects[wysiwyg][type] = module
projects[wysiwyg][download][type] = git
projects[wysiwyg][download][url] = http://git.drupal.org/project/wysiwyg.git
projects[wysiwyg][download][revision] = 37dc07db900cac540f30bca5d90bb75951cc314f

; Themes
projects[aurora][version] = "3.4"

; Libraries

libraries[ckeditor][type] = "libraries"
libraries[ckeditor][download][type] = "file"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.4.4/ckeditor_4.4.4_full.zip"

libraries[predis][download][type] = git
libraries[predis][download][url] = https://github.com/nrk/predis.git
libraries[predis][download][revision] = v0.8.7

libraries[wvega-timepicker][type] = "libraries"
libraries[wvega-timepicker][download][type] = "file"
libraries[wvega-timepicker][download][url] = "https://github.com/wvega/timepicker/archive/master.tar.gz"
