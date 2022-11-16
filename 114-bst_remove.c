#include "binary_trees.h"

/**
 * inorder_successor - Returns the value of the min value in BST.
 * @root: a pointer to the root node of the BST
 *
 * Return: the min value in @tree
 */
bst_t *inorder_successor(bst_t *root)
{
  while (root->left != NULL)
    root = root->left;
  return (root);
}

/**
 * bst_delete - deletes a node from a BST
 * @root: a pointer to the root node
 * @node: a pointer to the node to delete from the BST
 *
 * Return: a pointer to the new root node after deletion.
 */

bst_t *bst_delete(bst_t *root, bst_t *node)
{
  bst_t *parent = node->parent, *successor = NULL;

  /* No children or right-child only */
  if (node->left == NULL)
    {
      if (parent != NULL && parent->left == node)
	parent->left = node->right;
      else if (parent != NULL)
	parent->right = node->right;

      if (node->right != NULL)
	node->right->parent = parent;

      free(node);
      return (parent == NULL ? node->right : root);
    }

  /* left-child only */
  if (node->right == NULL)
    {
      if (parent != NULL && parent->left == node)
	parent->left = node->left;
      else if (parent != NULL)
	parent->right = node->left;

      if (node->left != NULL)
	node->left->parent = parent;

      free(node);
      return (parent == NULL ? node->left : root);
    }

  /* Two children */
  successor = inorder_successor(node->right);
  node->n = successor->n;

  return (bst_delete(root, successor));
}

/**
 * bst_rm_recursive - removes a node from a BST.
 * @root: a pointer to the root node of the BST.
 * @node: a pointer to the current node in the BST.
 * @value: value to remove from the BST.
 *
 * Return: a pointer to the root node after deletion
 */

bst_t *bst_rm_recursive(bst_t *root, bst_t *node, int value)
{
  if (node != NULL)
    {
      if (node->n == value)
	return (bst_delete(root, node));
      if (node->n > value)
	return (bst_rm_recursive(root, node->left, value));

      return (bst_rm_recursive(root, node->right, value));
    }
  return (NULL);
}

/**
 * bst_remove- removes a node from a BST
 * @root: a pointer to the root node of the BST
 * @value: the value to be removed from the BST
 *
 * Return: a pointer to the new root after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
  return(bst_rm_recursive(root, root, value));
}
