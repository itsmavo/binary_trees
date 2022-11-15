#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs right-rotation on a binary tree
 * @tree: a pointer to the root node
 *
 * Return: a pointer to the new root node of the rotated tree
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
  binary_tree_t *new_root;

  if (tree == NULL || tree->left == NULL)
    return (tree);

  new_root = tree->left;

  if (new_root->right)
    {
      tree->left = new_root->right;
      new_root->right->parent = tree;
    }
  else
    {
      tree->left = NULL;
    }

  new_root->right = tree;
  new_root->parent = tree->parent;
  tree->parent = new_root;

  return (new_root);
}
