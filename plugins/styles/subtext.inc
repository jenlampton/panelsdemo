<?php

/**
 * @file
 * Definition of the 'primary' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('SubText'),
  'description' => t('The subtext panel rendering style will make the pane appear just below the page heading.'),
  'render pane' => 'new_panels_subtext_style_render_pane',
  'weight' => -10,
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_new_panels_subtext_style_render_pane($vars) {
  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];
  
  // Add our own custom class
  $content->css_class = 'subtext';
  
  return theme('panels_pane', array('content' => $content, 'pane' => $pane, 'display' => $display));
}
