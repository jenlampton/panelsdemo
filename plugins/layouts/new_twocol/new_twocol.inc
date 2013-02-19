<?php

// Plugin definition
$plugin = array(
  'title' => t('Two column'),
  'category' => t('NEW'),
  'icon' => 'new_twocol.png',
  'theme' => 'new_twocol',
  'css' => 'new_twocol.css',
  'regions' => array(
    'left' => t('Main area'),
    'right' => t('Right sidebar'),
  ),
);
