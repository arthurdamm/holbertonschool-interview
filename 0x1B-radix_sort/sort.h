#ifndef SORT_H
#define SORT_H

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#define RADIX 10

void print_array(const int *array, size_t size);
void radix_sort(int *A, size_t size);
int count_sort(int *A, ssize_t size, int *B, long exp);

#endif
