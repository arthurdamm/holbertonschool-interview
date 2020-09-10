#include "sort.h"

/**
 * radix_sort - sorts by RADIX
 * @A: array to sort
 * @size: size of array
 */
void radix_sort(int *A, size_t size)
{
	size_t i;
	int max = INT_MIN, exp, *B;

	B = malloc(sizeof(*B) * size);
	if (!B)
		return;
	for (i = 0; i < size; i++)
		max = A[i] > max ? A[i] : max;
	for (exp = 1; max / exp > 0; exp *= RADIX)
	{
		if (count_sort(A, size, B, exp))
			print_array(A, size);
	}
	free(B);
}

/**
 * count_sort - sort by current digit
 * @A: array to sort
 * @size: size of array
 * @B: malloced temp array
 * @exp: current digital exponent
 * Return: if array changed
 */
int count_sort(int *A, ssize_t size, int *B, int exp)
{
	ssize_t i, j;
	int count[RADIX] = {0}, ret = 0;

	for (i = 0; i < size; i++)
		count[(A[i] / exp) % RADIX]++;
	for (i = 1; i < size; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		j = count[(A[i] / exp) % RADIX]-- - 1;
		if (i != j)
			ret = 1;
		B[j] = A[i];
	}
	for (i = 0; i < size; i++)
		A[i] = B[i];
	return (ret);
}
