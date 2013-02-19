<?php

/**
 * @file
 * Definition of the 'h4' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('H4 pane title'),
  'description' => t('The h4 panel rendering style will make the pane title use a h4 tag.'),
  'render pane' => 'jen_panels_h4_style_render_pane',
  'weight' => -10,
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_jen_panels_h4_style_render_pane($vars) {
  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];

  return theme('jen_panels_pane_h4', array('content' => $content, 'pane' => $pane, 'display' => $display));
}
