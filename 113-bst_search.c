#include "binary_trees.h"

/**
 * bst_search - searches for a value in a BST
 * @tree: a pointer to the root node
 * @value: the value to searched in the tree.
 *
 * Return: a pointer to the node containing a value == @value.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
  if (tree && value < tree->n)
    return (bst_search(tree->left, value));

  if (tree && value > tree->n)
    return (bst_search(tree->right, value));

  return ((bst_t *)tree);
}
