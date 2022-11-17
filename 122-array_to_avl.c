#include "binary_trees.h"

/**
 * array_to_avl - creates AVL tree from an array.
 * @array: a pointer to the first element of the array
 * @size: the number of elements in the array
 *
 * Return: a pointer to the root node of the created AVL tree
 */

avl_t *array_to_avl(int *array, size_t size)
{
  avl_t *tree = NULL;
  size_t i;

  for (i = 0; i < size; i++)
    avl_insert(&tree, array[i]);

  if (i == size)
    return (tree);

  return (NULL);
}
