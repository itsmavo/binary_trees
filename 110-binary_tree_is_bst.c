#include "binary_trees.h"
#include "limits.h"

/**
 * bst_helper - checks if a binary tree is a valid binary search tree.
 * @tree: a pointer to the root node of the tree.
 * @low: The value of the smallest node visited.
 * @high: The value of the largest node visited.
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */

int bst_helper(const binary_tree_t *tree, int low, int high)
{
  if (tree != NULL)
    {
      if (tree->n < low || tree->n > high)
	return (0);

      return (bst_helper(tree->left, low, tree->n - 1) &&
	      bst_helper(tree->right, tree->n + 1, high));
    }

  return (1);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree.
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 if BST is valid, 0 otherwise.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
  if (tree)
    return (bst_helper(tree, INT_MIN, INT_MAX));

  return (0);
}
