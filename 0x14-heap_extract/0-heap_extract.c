#include "binary_trees.h"

/**
 * heap_size - gets size of heap
 * @heap: pointer to root
 * Return: size of heap
 */
int heap_size(heap_t *heap)
{
	return (heap ? 1 + heap_size(heap->left) + heap_size(heap->right) : 0);
}

/**
 * heapify_down - restores the min heap property from root down
 * @heap: pointer to heap struct
 */
void heapify_down(heap_t *heap)
{
	heap_t *node = heap, *child;
	int temp;

	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			child = node->left;
		else
			child = node->left->n > node->right->n ?
				node->left : node->right;
		if (node->n > child->n)
			break;
		temp = node->n;
		node->n = child->n;
		child->n = temp;
		node = child;
	}
}

/**
 * heap_extract - extracts top node from min heap
 * @heap: pointer to heap struct
 * Return: node n value
 */
int heap_extract(heap_t **heap)
{
	int n, size, bit;
	heap_t *node, *root;

	if (!heap || !*heap)
		return (0);
	root = *heap;
	n = root->n;
	size = heap_size(root);
	if (size == 1)
	{
		free(root);
		*heap = NULL;
		return (n);
	}
	for (bit = 1; bit <= size; bit <<= 1)
		;
	bit >>= 2;
	for (node = root; bit > 0; bit >>= 1)
		node = size & bit ? node->right : node->left;
	root->n = node->n;
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	free(node);
	heapify_down(root);
	*heap = root;
	return (n);
}
