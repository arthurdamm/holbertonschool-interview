#include "sort.h"

/**
 * merge_sort - sorts via top-down merge (divide & conquer!)
 * @array: the int array to sort in place
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *copy = malloc(sizeof(*copy) * size), *end = array + size;

	if (copy && size > 1)
	{
		while (array < end)
			*copy++ = *array++;
		sort(array - size, copy - size, size);
	}
	copy ? free(size > 1 ? copy - size : copy) : (void)0;
}

/**
 * sort - recursively sorts via top-down merge (divide & conquer!)
 * @A: the int array to sort in place
 * @B: copy of array for O(n) space
 * @size: size of arrays
 */
void sort(int *A, int *B, size_t size)
{
	if (size > 1)
		sort(B, A, size / 2),
		sort(B + size / 2, A + size / 2, size - size / 2),
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

	printf("Merging...\n[left]: "), print_array(B, size / 2);
	printf("[right]: "), print_array(B + size / 2, size - size / 2);
	while (i < B + size / 2 || j < B + size)
		*A++ = i < B + size / 2 && (j >= B + size || *i <= *j) ? *i++ : *j++;
	printf("[Done]: "), print_array(A - size, size);
}
