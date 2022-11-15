#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node
 *
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
  if (tree)
    return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);

  return (0);
}

/**
 * is_tree_complete - checks if tree is complete
 * @tree: a pointer to the root node
 * @index: index of the node
 * @nodes: number of nodes
 *
 * Return: 1 if tree is complete, 0 otherwise
 */

int is_tree_complete(const binary_tree_t *tree, int index, int nodes)
{
  if (tree == NULL)
    return (1);

  if (index >= nodes)
    return (0);

  return (is_tree_complete(tree->left, (2 * index) + 1, nodes) &&
	  is_tree_complete(tree->right, (2 * index) + 2, nodes));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: a pointer to the root node
 *
 * Return: 1 if complete, 0 is otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
  size_t nodes;
  if (tree)
    {
      nodes = binary_tree_size(tree);
      return (is_tree_complete(tree, 0, nodes));
    }

  return (0);
}
