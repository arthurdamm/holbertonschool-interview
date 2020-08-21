#include "sort.h"

#define UP(x) ((x - 1) / 2)
#define LEFT(x) (2 * x + 1)
#define RIGHT(x) (2 * x + 2)

/**
 * heap_sort - uses heapify sift-down to sort A in-place
 * @A: A to sort in-place
 * @size: size of A
 */
void heap_sort(int *A, size_t size)
{
	size_t len = size;

	if (size < 2)
		return;
	heapify(A, size);
	while (len > 1)
		swap(A, 0, len - 1, size),
		sift_down(A, 0, --len, size);
}

/**
 * heapify - turns array into max heap
 * @A: pointer to array
 * @size: size of array
 */
void heapify(int *A, size_t size)
{
	ssize_t start = UP(size - 1);

	while (start >= 0)
		sift_down(A, start--, size, size);
}

/**
 * sift_down - performs heap sift-down operation
 * @A: pointer to array
 * @start: starting index
 * @len: current length of heap
 * @size: size of array
 */
void sift_down(int *A, size_t start, size_t	len, size_t size)
{
	size_t root = start, temp = root;

	while (LEFT(root) < len)
	{
		temp = root;
		if (A[LEFT(root)] > A[root])
			temp = LEFT(root);
		if (RIGHT(root) < len &&
			A[RIGHT(root)] > A[temp])
			temp = RIGHT(root);
		if (temp == root)
			break;
		swap(A, root, temp, size);
		root = temp;
	}
}

/**
 * swap - swaps two elements in array
 * @A: pointer to array
 * @a: index of first element
 * @b: index of second element
 * @size: size of array
 */
inline void swap(int *A, size_t a, size_t b, size_t size)
{
	int temp = A[a];

	A[a] = A[b];
	A[b] = temp;
	print_array(A, size);
}
