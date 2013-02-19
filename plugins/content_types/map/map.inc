<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('US Map'),
  'no title override' => TRUE,
  'defaults' => array(),
  'icon' => 'ptr.png',
  'description' => t('US Map'),
  'category' => t('Widgets'),
  'edit text' => t('Configure'),
);

/**
 * Render the custom content type.
 */
function jen_panels_map_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = t('Find info on schools and colleges offering pharmacy technician programs in your state:');

  $css_path = drupal_get_path('module', 'jen_panels') . '/plugins/content_types/map/map.css';
  drupal_add_css($css_path);

  $js_magic = "<!--Below is the class function for the image map 'class=map'-->
  (function ($) {  
    $(function() {
      $('map > area').easyTooltip();  /*Tooltip function with area tag*/
    });
  })(jQuery);";
  $js_path_meta = drupal_get_path('module', 'jen_panels') . '/plugins/content_types/map/js/jquery.metadata.min.js';
  $js_path_tooltip = drupal_get_path('module', 'jen_panels') . '/plugins/content_types/map/js/easyTooltip.js';

  drupal_add_js($js_path_meta);
  drupal_add_js($js_path_tooltip);
  drupal_add_js($js_magic, 'inline');

  // Image info
  $path = drupal_get_path('module', 'jen_panels') . '/plugins/content_types/map/usa.png';
  $alt = '';
  $title = '';
  $attributes = array(
    'name' => 'usa',
    'usemap' => '#usa',
    'class' => 'map',
    'id' => 'usa',
    );

  // image map.
  $file_path = drupal_get_path('module', 'jen_panels') . '/plugins/content_types/map/map.html';

  $block->content = theme('image', array('path' => $path, 'alt' => $alt, 'title' => $title, 'attributes' => $attributes));
  $block->content .= file_get_contents('./' . $file_path);

  return $block;
}
