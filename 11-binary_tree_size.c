#include "binary_trees.h"

/**
 * binary_tree_size - measures size of the binary size.
 * @tree: a pointer to the root node of the tree.
 *
 * Return: size of the tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
  size_t lsize, rsize;

  if (tree)
    {
      lsize = binary_tree_size(tree->left);
      rsize = binary_tree_size(tree->right);

      return (lsize + rsize + 1);
    }

  return (0);
}
