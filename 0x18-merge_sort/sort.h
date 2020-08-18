#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void merge_sort(int *array, size_t size);
void sort(int *A, int *B, size_t size);
void merge(int *A, int *B, size_t size);

void print_array(const int *array, size_t size);

#endif
