#ifndef SANDPILES_H
#define SANDPILES_H

#include "stddef.h"
#include "stdio.h"

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void add_sandpile(int grid1[3][3], int grid2[3][3]);
int is_unstable(int grid[3][3]);
void topple_sandpile(int grid1[3][3], int grid2[3][3]);
void print_sandpile(int grid[3][3]);

#endif
