#include "binary_trees.h"

/**
 * is_balance - checks the balance of each node
 * @node: pointer to the node
 * @value: input value
 *
 * Return: void
 */

void is_balance(avl_t **node, int value)
{
  int balance = binary_tree_balance(*node);

  if (balance > 1 && value < (*node)->left->n)
    {
      *node = binary_tree_rotate_right(*node);
      return;
    }

  if (balance < -1 && value > (*node)->right->n)
    {
      *node = binary_tree_rotate_left(*node);
      return;
    }

  if (balance > 1 && value > (*node)->left->n)
    {
      (*node)->left = binary_tree_rotate_left((*node)->left);
      *node = binary_tree_rotate_right(*node);
      return;
    }

  if (balance < -1 && value < (*node)->right->n)
    {
      (*node)->right = binary_tree_rotate_right((*node)->right);
      *node = binary_tree_rotate_left(*node);
      return;
    }
}

/**
 * avl_ins - checks of node is inserted
 * @tree: a pointer to the root node
 * @value: node value
 *
 * Return: a pointer to the new node
 */

avl_t *avl_ins(avl_t **tree, int value)
{
  avl_t *node;

  if (value < (*tree)->n)
    {
      if ((*tree)->left == NULL)
	{
	  (*tree)->left = binary_tree_node(*tree, value);
	  return ((*tree)->left);
	}
      else
	{
	  node = avl_ins(&((*tree)->left), value);
	  if (node)
	    is_balance(tree, value);
	  return (node);
	}
    }

  if (value > (*tree)->n)
    {
      if ((*tree)->right == NULL)
	{
	  (*tree)->right = binary_tree_node(*tree, value);
	  return ((*tree)->right);
	}
      else
	{
	  node = avl_ins(&((*tree)->right), value);
	  if (node)
	    is_balance(tree, value);
	  return (node);
	}
    }
  return (NULL);
}

/**
 * avl_insert - inserts a value in a AVL tree
 * @tree: a pointer to the root node
 * @value: node value
 *
 * Return: a pointer to the new node
 */

avl_t *avl_insert(avl_t **tree, int value)
{
  avl_t *node;

  if (*tree == NULL)
    {
      *tree = binary_tree_node(NULL, value);
      return (*tree);
    }

  node = avl_ins(tree, value);

  return (node);
}
