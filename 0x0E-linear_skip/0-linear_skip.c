#include "search.h"

/**
 * linear_skip - search via linear skip
 * @list: pointer to skip list
 * @value: to search for
 * Return: address of node or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *fast = list;

	if (!list)
		return (NULL);
	while (fast->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			fast->express->index, fast->express->n);
		if (fast->express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				fast->index, fast->express->index);
			break;
		}
		fast = fast->express;
	}
	if (!fast->express)
	{
		for (list = fast; list->next; list = list->next)
			;
		printf("Value found between indexes [%lu] and [%lu]\n",
				fast->index, list->index);
	}
	for (list = fast; list != fast->express; list = list->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (value == list->n)
			break;
	}
	return (list == fast->express ? NULL : list);
}
