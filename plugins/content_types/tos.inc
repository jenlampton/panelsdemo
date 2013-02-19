<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Terms of use'),
  'no title override' => TRUE,
  'defaults' => array(),
  'icon' => 'dsd.gif',
  'description' => t('Terms of use'),
  'category' => t('DSD'),
  'edit text' => t('Configure'),
);

/**
 * Render the custom content type.
 */
function jen_panels_tos_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->content  = '<p>' . t('Please read our <a href="!url">User Agreement</a> 
    before browsing our website or using this Service. By continuing to use 
    this site, you agree to abide by the conditions of this User 
    Agreement.', array('!url' => url('node/1338'))) . '</p>';

  return $block;
}
