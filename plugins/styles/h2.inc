<?php

/**
 * @file
 * Definition of the 'h2' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('H2 pane title'),
  'description' => t('The h2 panel rendering style will make the pane title use a h2 tag.'),
  'render pane' => 'jen_panels_h2_style_render_pane',
  'weight' => -10,
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_jen_panels_h2_style_render_pane($vars) {
  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];

  return theme('jen_panels_pane_h2', array('content' => $content, 'pane' => $pane, 'display' => $display));
}
