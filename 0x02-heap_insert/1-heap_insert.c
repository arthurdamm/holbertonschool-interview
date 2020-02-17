#include "binary_trees.h"

/**
 * heap_insert - inserts new value into MAX HEAP
 * @root: address of ptr to root node
 * @value: the integer value of the node
 * Return: ptr to new node or NULL on error.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	ssize_t n = get_heap_size(*root) + 1;
	int bit = 0;
	heap_t *node = *root, *new_node;

	new_node = binary_tree_node(node, value);
	if (!new_node)
		return (NULL);
	if (!*root)
		return (*root = new_node);
	for (; 1 << (bit + 1) <= n; bit++)
		;
	for (bit--; bit > 0; bit--)
	{
		if (n & (1 << bit))
			node = node->right;
		else
			node = node->left;
	}
	if (n & 1)
		node->right = new_node;
	else
		node->left = new_node;
	new_node->parent = node;
	return (heapify(new_node));
}

/**
 * get_heap_size - gets number of nodes in heap
 * @root: pointer to root node
 * Return: number of nodes
 */
size_t get_heap_size(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + get_heap_size(root->left) + get_heap_size(root->right));
}

/**
 * heapify - ensures Max Heap property
 * @node: node to start heapification
 * Return: pointer to starting node
 */
heap_t *heapify(heap_t *node)
{
	while (node && node->parent && node->n > node->parent->n)
	{
		node->parent->n -= node->n;
		node->n = node->parent->n + node->n;
		node->parent->n = node->n - node->parent->n;
		node = node->parent;
	}
	return (node);
}
