<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Comments and comment form.'),
  'icon' => 'icon_node.png',
  'description' => t('The comments and comment form for the referenced node.'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('Node'),
  'defaults' => array(
    'mode' => variable_get('comment_default_mode', COMMENT_MODE_THREADED),
    'comments_per_page' => variable_get('comment_default_per_page', '50'),
  ),
);

function jen_panels_comment_wrapper_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? clone($context->data) : NULL;
  $block = new stdClass();
  $block->module = 'comments';
  $block->delta  = $node->nid;

  $renderable = array(
    '#theme' => 'comment_wrapper__node_' . $node->type,
    '#node' => $node,
    'comments' => array(),
    'comment_form' => array(),
  );

  // Add in the comments.
  if (user_access('access comments') || user_access('administer comments')) {
    $mode = $conf['mode'];
    $comments_per_page = $conf['comments_per_page'];
    if ($cids = comment_get_thread($node, $mode, $comments_per_page)) {
      $comments = comment_load_multiple($cids);
      comment_prepare_thread($comments);
      $build = comment_view_multiple($comments, $node);
      $build['pager']['#theme'] = 'pager';
      $renderable['comments'] = $build;
    }
  }

  // Stuff in the comment form. 
  if ($node->comment == COMMENT_NODE_OPEN) {
    if (user_access('post comments')) {
      $comment = new stdClass();
      $comment->nid = $node->nid;
      $comment->pid = NULL;
      $form_state = array(
        'ctools comment alter' => TRUE,
        'node' => $node,
        'build_info' => array(
          'args' => array(
            $comment,
          ),
        ),
      );
      $renderable['comment_form'] = drupal_build_form('comment_node_' . $node->type . '_form', $form_state);
    }
  }

  $block->content = drupal_render($renderable);

  return $block;
}

function jen_panels_comment_wrapper_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['mode'] = array(
    '#type' => 'select',
    '#title' => t('Mode'),
    '#default_value' => $conf['mode'],
    '#options' => _comment_get_modes(),
    '#weight' => 1,
  );
  foreach (_comment_per_page() as $i) {
    $options[$i] = t('!a comments per page', array('!a' => $i));
  }
  $form['comments_per_page'] = array('#type' => 'select',
    '#title' => t('Pager'),
    '#default_value' => $conf['comments_per_page'],
    '#options' => $options,
    '#weight' => 3,
  );
  return $form;
}

function jen_panels_comment_wrapper_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function jen_panels_comment_wrapper_content_type_admin_title($subtype, $conf, $context) {
  return t('Comments and comment form');
}