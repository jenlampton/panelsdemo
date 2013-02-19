<?php

/**
 * @file
 * Definition of the 'h3' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('H3 pane title'),
  'description' => t('The h3 panel rendering style will make the pane title use a h3 tag.'),
  'render pane' => 'jen_panels_h3_style_render_pane',
  'weight' => -10,
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_jen_panels_h3_style_render_pane($vars) {
  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];

  return theme('jen_panels_pane_h3', array('content' => $content, 'pane' => $pane, 'display' => $display));
}
