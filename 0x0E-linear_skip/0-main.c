#include <stdio.h>
#include <stdlib.h>

#include "search.h"

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	skiplist_t *list, *res;
	int array[] = {
		9,
	};
	int d;
	size_t size = sizeof(array) / sizeof(array[0]);

	list = create_skiplist(array, size);


	d = 0;
	res =  linear_skip(list, d);
	printf("Found %d at index: %ld\n\n", d, res ? res->index : 98);
	d = 2;
	res =  linear_skip(list, d);
	printf("Found %d at index: %ld\n\n", d, res ? res->index : 98);
	d = 99;
	res =  linear_skip(list, d);
	printf("Found %d at index: %p\n", d, (void *) res);

	free_skiplist(list);
	return (EXIT_SUCCESS);
}
