<?php

/**
 * @file
 * Plugin to provide access control based upon a parent term.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Book - Top level"),
  'description' => t('Control access by book structure.'),
  'callback' => 'jen_panels_book_top_ctools_access_check',
  'default' => array('negate' => 0),
  'settings form' => 'jen_panels_book_top_ctools_access_settings',
  //'settings form validation' => 'jen_panels_book_top_ctools_access_settings_validate',
  //'settings form submit' => 'jen_panels_book_top_ctools_access_settings_submit',
  'summary' => 'jen_panels_book_top_ctools_access_summary',
);

/**
 * Settings form for the 'by parent term' access plugin
 */
function jen_panels_book_top_ctools_access_settings($form, &$form_state, $conf) { 
  // @todo: do I need any settings?
  return $form;
}

/**
 * Check for node type and book location.
 */
function jen_panels_book_top_ctools_access_check($conf, $context) {
  // Get the node.
  if (arg(0) == 'node' && is_numeric(arg(1)) && !arg(2)) {
    $node = node_load(arg(1));
    if ($node->type == 'book') {
      // Get the book position.
      $toc = book_toc(1555, 2);
      // Get the node link parent.
      $mlid = db_query("SELECT mlid FROM {menu_links} WHERE menu_name = 'book-toc-1555' AND link_path = :path", array(':path' => 'node/' . $node->nid))->fetchField();
      if (array_key_exists($mlid, $toc)) {
        return TRUE;
      }
    }
  }

  return FALSE;
}

/**
 * Provide a summary description based upon the checked terms.
 */
function jen_panels_book_top_ctools_access_summary($conf, $context) {
  return t('Book page is top level');
}
