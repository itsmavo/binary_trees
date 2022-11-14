#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through the binary tree using pre-order traversal.
 * @tree: a pointer to the root of the tree to traverse
 * @func: is pointer to the function to cal for each node. The value in the node must be passed as a parameter of the function.
 *
 * Return: void
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
  if (tree && func)
    {
      func(tree->n);
      binary_tree_preorder(tree->left, func);
      binary_tree_preorder(tree->right, func);
    }
}
