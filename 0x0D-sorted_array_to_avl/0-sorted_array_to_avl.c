#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - inserts sorted array to AVL tree
 * @array: the sorted array
 * @size: the size of the array
 * Return: node to head of AVL tree or NULL on error
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t mid;
	avl_t *parent, *left, *right = NULL;

	if (!array || !size)
		return (NULL);
	parent = calloc(1, sizeof(avl_t));
	if (!parent)
		return (NULL);
	if (size == 1)
	{
		parent->n = array[0];
		return (parent);
	}
	mid = size / 2;
	parent->n = array[mid];
	left = sorted_array_to_avl(array, mid);
	if (mid + 1 < size)
		right = sorted_array_to_avl(array + mid + 1, size - mid - 1);
	parent->left = left;
	if (left)
		left->parent = parent;
	parent->right = right;
	if (right)
		right->parent = parent;
	return (parent);
}
