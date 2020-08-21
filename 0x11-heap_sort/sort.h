#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void heap_sort(int *A, size_t size);
void heapify(int *A, size_t size);
void sift_down(int *A, size_t start, size_t	len, size_t size);
inline void swap(int *A, size_t a, size_t b, size_t size);

#endif
