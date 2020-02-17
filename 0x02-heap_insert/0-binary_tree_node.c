#include "binary_trees.h"

/**
 * binary_tree_node - adds node to binary tree
 * @parent: pointer to the parent node
 * @value: the integer value of the node
 * Return: ptr to new node or NULL on error.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(*node));

	if (!node)
		return (NULL);
	memset(node, 0, sizeof(*node));
	node->parent = parent;
	node->n = value;
	return (node);
}
