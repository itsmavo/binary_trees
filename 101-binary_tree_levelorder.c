#include "binary_trees.h"
/**
 * recursive_height - measures height of a binary tree
 * @tree: root of the node
 *
 * Return: height of the binary tree
 */

size_t recursive_height(const binary_tree_t *tree)
{
  size_t left = 0, right = 0;

  if (tree)
    {
      left = recursive_height(tree->left);
      right = recursive_height(tree->right);

      if (left > right)
	return (left + 1);

      return (right + 1);
    }

  return (0);
}

/**
 * print_level - prints nodes at the same level
 * @tree: root of the tree
 * @level: level of the node in the binary tree
 * @func: pointer to the function
 *
 * Return: void
 */

void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
  if (tree)
    {
      if (level == 1)
	func(tree->n);
      else if (level > 1)
	{
	  print_level(tree->left, level - 1, func);
	  print_level(tree->right, level - 1, func);
	}
    }
  return;
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: a pointer to the root node of the tree
 * @func: a pointer to a function to call for each node. The value in the node
 *        is a parameter
 * Return: returns a binary tree in level-order traversal
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
  size_t height, i;

  if (tree && func)
    {
      height = recursive_height(tree);

      for (i = 1; i <= height; i++)
	print_level(tree, i, func);
    }
  return;
}
