<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('One column'),
  'category' => t('NEW'),
  'icon' => 'new_onecol.png',
  'theme' => 'new_onecol',
  'css' => 'new_onecol.css',
  'regions' => array('middle' => t('Middle column')),
);
