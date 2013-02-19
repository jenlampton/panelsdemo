<?php

/**
 * @file
 * Definition of the 'notitle' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('No pane title'),
  'description' => t('The no pane title rendering style will make the pane render without a title.'),
  'render pane' => 'jen_panels_notitle_style_render_pane',
  'weight' => -10,
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_jen_panels_notitle_style_render_pane($vars) {
  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];

  return theme('jen_panels_pane_notitle', array('content' => $content, 'pane' => $pane, 'display' => $display));
}
