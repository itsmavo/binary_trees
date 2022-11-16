#include "binary_trees.h"

/**
 * array_to_bst - builds a BST from an array
 * @array: a pointer to the first element of the array.
 * @size:  number of elements in the array.
 *
 * Return: a pointer to the root node of the BST
 */

bst_t *array_to_bst(int *array, size_t size)
{
  bst_t *tree;
  size_t i;

  tree = NULL;

  for (i = 0; i < size; i++)
    bst_insert(&tree, array[i]);

  if (i == size)
    return (tree);

  return (NULL);
}
