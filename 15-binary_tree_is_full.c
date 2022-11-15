#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if binary tree is full
 * @tree: a pointer to the root of the tree.
 *
 * Return: 1 if full, 0 if empty.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
  if (tree)
    {
      if (tree->left == NULL && tree->right == NULL)
	return (1);

      if (tree->left && tree->right)
	return (binary_tree_is_full(tree->left) &&
		binary_tree_is_full(tree->right));
    }

  return (0);
}
