#include "binary_trees.h"
#include "14-binary_tree_balance.c"
#include "15-binary_tree_is_full.c"

/**
 * check_level_leaves - checks if all leaves are on the same level.
 * @tree: node to start on
 * @current: level of current leaf
 * @level: level of past leaves
 *
 * Return: 1 if true, 0 if otherwise
 */

int check_level_leaves(const binary_tree_t *tree, int current, int *level)
{
  if (tree)
    {
      if (tree->right == NULL && tree->left == NULL)
	{
	  if (*level == 0)
	    {
	      *level = current;
	      return (1);
	    }
	  
	  return (*level == current);
	}
      
      return (check_level_leaves(tree->left, current + 1, level) &&
	      check_level_leaves(tree->right, current + 1, level));
    }
  
  return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree.
 *
 * Return: 1 if perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
  int level = 0;

  if (tree)
    {
      if (binary_tree_is_full(tree) && (!binary_tree_balance(tree)))
	return (check_level_leaves(tree, 0, &level));
    }

  return (0);
}
