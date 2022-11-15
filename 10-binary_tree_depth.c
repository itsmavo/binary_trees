#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: a pointer to the node to measure depth.
 *
 * Return: depth of the binary tree from a node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
  return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
