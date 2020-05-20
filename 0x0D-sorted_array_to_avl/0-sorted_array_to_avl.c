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
	avl_t *parent;

	if (!array || size < 1)
		return (NULL);
	parent = calloc(1, sizeof(avl_t));
	if (!parent)
		return (NULL);
	mid = size / 2;
	parent->n = array[mid];
	parent->left = sorted_array_to_avl(array, mid);
	parent->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);
	parent->left ? parent->left->parent = parent : 0;
	parent->right ? parent->right->parent = parent : 0;
	return (parent);
}
