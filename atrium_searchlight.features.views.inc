<?php

/**
 * Helper to implementation of hook_views_default_views().
 */
function _atrium_searchlight_views_default_views() {
  $views = array();

  // Exported view: search_faceted
  $view = new view;
  $view->name = 'search_faceted';
  $view->description = 'Atrium > Search';
  $view->tag = 'atrium';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'feature' => array(
      'label' => '',
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'feature',
      'table' => 'spaces_node',
      'field' => 'feature',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => 'Title',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'body' => array(
      'label' => 'Body',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '250',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 1,
        'html' => 0,
      ),
      'exclude' => 0,
      'id' => 'body',
      'table' => 'node_revisions',
      'field' => 'body',
      'relationship' => 'none',
    ),
    'name' => array(
      'label' => 'Author',
      'link_to_user' => 1,
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'none',
    ),
    'last_updated' => array(
      'label' => 'Last post',
      'date_format' => 'reldate',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'last_updated',
      'table' => 'node_comment_statistics',
      'field' => 'last_updated',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'changed' => array(
      'order' => 'DESC',
      'granularity' => 'year',
      'id' => 'changed',
      'table' => 'node',
      'field' => 'changed',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'created_year_month' => array(
      'default_action' => 'ignore',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => 'Search results (%1)',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'id' => 'created_year_month',
      'table' => 'node',
      'field' => 'created_year_month',
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => 'all',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'blog' => 0,
        'book' => 0,
        'event' => 0,
        'feedapi_node' => 0,
        'feed_ical' => 0,
        'feed_ical_item' => 0,
        'group' => 0,
        'page' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '5' => 0,
        '1' => 0,
        '2' => 0,
        '6' => 0,
        '4' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => 1,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'current' => array(
      'operator' => 'active',
      'value' => 'all',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'current',
      'table' => 'spaces',
      'field' => 'current',
      'relationship' => 'none',
    ),
    'facets' => array(
      'id' => 'facets',
      'table' => 'searchlight',
      'field' => 'facets',
    ),
    'search' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'operator' => '',
        'identifier' => 'search',
        'label' => 'Search',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
      ),
      'hideEmpty' => 1,
      'matchMode' => '0',
      'id' => 'search',
      'table' => 'searchlight',
      'field' => 'search',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'access content',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Search');
  $handler->override_option('items_per_page', 25);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 1,
    'order' => 'asc',
    'columns' => array(
      'feature' => 'feature',
      'title' => 'title',
      'body' => 'title',
      'name' => 'name',
      'last_updated' => 'last_updated',
    ),
    'info' => array(
      'feature' => array(
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 0,
        'separator' => '<br/>',
      ),
      'body' => array(
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'last_updated' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'search/posts');
  $handler->override_option('menu', array(
    'type' => 'default tab',
    'title' => 'Posts',
    'description' => '',
    'weight' => '-1',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'normal',
    'title' => 'Search',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler = $view->new_display('page', 'Page', 'page_2');
  $handler->override_option('relationships', array(
    'upload_fid' => array(
      'label' => 'Files',
      'required' => 1,
      'id' => 'upload_fid',
      'table' => 'node',
      'field' => 'upload_fid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'filemime' => array(
      'label' => 'Type',
      'link_to_file' => 1,
      'exclude' => 0,
      'id' => 'filemime',
      'table' => 'files',
      'field' => 'filemime',
      'relationship' => 'upload_fid',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'filename' => array(
      'label' => 'Filename',
      'link_to_file' => 1,
      'exclude' => 0,
      'id' => 'filename',
      'table' => 'files',
      'field' => 'filename',
      'relationship' => 'upload_fid',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'title' => array(
      'label' => 'Title',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'last_updated' => array(
      'label' => 'Last post',
      'date_format' => 'reldate',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'last_updated',
      'table' => 'node_comment_statistics',
      'field' => 'last_updated',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('path', 'search/files');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'Files',
    'description' => '',
    'weight' => '1',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $translatables['search_faceted'] = array(
    t('Defaults'),
    t('Page'),
    t('Search'),
  );

  $views[$view->name] = $view;

  return $views;
}