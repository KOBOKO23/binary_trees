#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array.
 * @array: a pointer to the first element of the array to be converted.
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created BST, or NULL on failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t j;
	bst_t *root = NULL;

	if (!array)
		return (NULL);
	for (j = 0; j < size; j++)
		bst_insert(&root, array[j]);
	return (root);
}
