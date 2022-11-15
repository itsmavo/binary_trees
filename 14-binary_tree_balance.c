#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance of a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: balance factor of the tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
  if (tree)
    return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

  return (0);
}

/**
 * binary_tree_height - measures height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: height of the binary tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
  if (tree)
    {
      size_t lf = 0, rt = 0;

      lf = tree->left ? 1 + binary_tree_height(tree->left) :1;
      rt = tree->right ? 1 + binary_tree_height(tree->right) :1;
      return ((lf > rt) ? lf : rt);
    }
  return (0);
}
