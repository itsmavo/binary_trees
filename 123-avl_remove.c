#include "binary_trees.h"

void is_balance(avl_t **node, int value);
/**
 * inorder_succesor - determines the next/previous node of the removed
 *                    node by the next/previous node
 * @tree: pointer to the node
 * @mode: 1 for inorder succesor, 2 for inorder precessor
 *
 * Return: pointer to the next/previous node 
 */

avl_t *inorder_successor(avl_t *tree, int mode)
{
  avl_t *node;

  if (mode == 1)
    {
      if (tree->left == NULL)
	{
	  if (tree == tree->parent->left)
	    tree->parent->left = NULL;
	  else
	    tree->parent->right = NULL;

	  return (tree);
	}
      node = inorder_successor(tree->left, 1);
    }
  else
    {
      if (tree->right == NULL)
	{
	  if (tree == tree->parent->right)
	    tree->parent->right = NULL;
	  else
	    tree->parent->left = NULL;

	  return (tree);
	}
      node = inorder_successor(tree->right, 2);
    }
  return (node);
}

/**
 * change_node - changes the removes node by the next/previous node
 * @arg_tree: pointer to the removed node
 * @arg_node: pointer to the next/previous node
 *
 * Return: void
 */

void change_node(avl_t **arg_tree, avl_t **arg_node)
{
  avl_t *put_node, *tree;
  put_node = *arg_node;
  tree = *arg_tree;

  if (tree->left && tree->left != put_node)
    {
      if(put_node->left)
	{
	  put_node->parent->right = put_node->left;
	  put_node->left->parent = put_node->parent;
	}
      put_node->left = tree->left;
      tree->left->parent = put_node;
    }

  if (tree->right && tree->right != put_node)
    {
      if (put_node->right)
	{
	  put_node->parent->left = put_node->right;
	  put_node->right->parent = put_node->parent;
	}
      put_node->right = tree->right;
      tree->right->parent = put_node;
    }

  put_node->parent = tree->parent;

  if (tree->parent)
    {
      if (tree->parent->left == tree)
	tree->parent->left = put_node;
      else
	tree->parent->right = put_node;
    }

  *arg_tree = tree;
  *arg_node = put_node;
}

/**
 * avl_search_remove - searches to remove a node in an AVL tree
 * @tree: a pointer to the root node of the tree
 * @value: value of the node
 *
 * Return: a pointer to the removed node
 */

avl_t *avl_search_remove(avl_t **tree, int value)
{
  avl_t *put_node;

  if (tree && *tree && value < (*tree)->n)
    {
      put_node = avl_search_remove(&((*tree)->left), value);
      is_balance(tree, value);
      return (put_node);
    }

  if (tree && *tree && value > (*tree)->n)
    {
      put_node = avl_search_remove(&((*tree)->right), value);
      is_balance(tree, value);
      return (put_node);
    }
  if (tree && *tree)
    {
      if ((*tree)->left || (*tree)->right)
	{
	  if ((*tree)->right)
	    put_node = inorder_successor((*tree)->right, 1);
	  else
	    put_node = inorder_successor((*tree)->left, 2);

	  change_node(tree, &put_node);
	  free(*tree);
	  *tree = put_node;
	}
      else
	{
	  put_node = *tree;
	  if ((*tree)->parent)
	    {
	      if ((*tree)->parent->left == (*tree))
		(*tree)->parent->left = NULL;
	      else
		(*tree)->parent->right = NULL;
	    }
	  free(put_node), *tree = NULL;
	}
    }
  return (*tree);
}
/**
 * avl_remove - removes a node from an AVL tree
 * @root: a pointer to the root node of the tree
 * @value: the value to be removed from the tree
 *
 * Return: return a pointer to the new root  node of the tree
 *         after removing selected value, and after rebalancing.
 */

avl_t *avl_remove(avl_t *root, int value)
{
  if (root == NULL)
    return (NULL);
  avl_search_remove(&root, value);

  return (root);
}
