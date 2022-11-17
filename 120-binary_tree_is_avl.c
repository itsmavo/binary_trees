#include "binary_trees.h"
#include "limits.h"
/**
 * height - measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree
 *
 * Return: height, otherwise 0.
 */
size_t height(const binary_tree_t *tree)
{
  if (tree)
    {
      size_t l = 0, r = 0;

      l = tree->left ? 1 + height(tree->left) : 1;
      r = tree->right ? 1 + height(tree->right) : 1;
      return ((l > r) ? l : r);
    }
  return (0);
}
/**
 * is_avl_helper - checks if a binary tree is a valid AVL tree
 * @tree: a pointer to the root node of the tree
 * @low: value of the smallest node visted
 * @high: value of the largest node visited
 *
 * Return: 1 if node is a AVL, otherwise 0
 */
int is_avl_helper(const binary_tree_t *tree, int low, int high)
{
  size_t lht, rht, diff;

  if (tree != NULL)
    {
      if (tree->n < low || tree->n > high)
	return(0);
      lht = height(tree->left);
      rht = height(tree->right);
      diff = lht > rht ? lht - rht : rht - lht;
      if (diff > 1)
	return (0);
      return (is_avl_helper(tree->left, low, tree->n - 1) &&
	      is_avl_helper(tree->right, tree->n + 1, high));
    }
  return (1);
}
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree.
 * @tree: a pointer to the root node of the tree.
 *
 * Return: 1 if valid AVL tree, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
  if (tree == NULL)
    return (0);
  return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
