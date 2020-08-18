#include "sort.h"

/**
 * merge_sort - sorts via top-down merge (divide & conquer!)
 * @array: the int array to sort in place
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t i = -1;

	if (size < 2)
		return;
	copy = malloc(sizeof(*copy) * size);
	if (!copy)
		return;
	while (++i < size)
		copy[i] = array[i];
	sort(array, copy, size);
	free(copy);
}

/**
 * sort - recursively sorts via top-down merge (divide & conquer!)
 * @A: the int array to sort in place
 * @B: copy of array for O(n) space
 * @size: size of arrays
 */
void sort(int *A, int *B, size_t size)
{
	if (size < 2)
		return;
	sort(B, A, size / 2);
	sort(B + size / 2, A + size / 2, size - size / 2);
	merge(A, B, size);
}

/**
 * merge - merges two sorted sub-arrays
 * @A: the int array to sort in place
 * @B: copy of array for O(n) space
 * @size: size of arrays
 */
void merge(int *A, int *B, size_t size)
{
	int *i = B, *j = B + size / 2;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(B, size / 2);
	printf("[right]: ");
	print_array(B + size / 2, size - size / 2);

	while (i < B + size / 2 || j < B + size)
		if (i < B + size / 2 && (j >= B + size || *i <= *j))
			*A++ = *i++;
		else
			*A++ = *j++;

	printf("[Done]: ");
	print_array(A - size, size);

}
