#include "sandpiles.h"

/**
 * sandpiles_sum - computes the final stable sum of two sandpiles
 * @grid1: the first sandpile
 * @grid2: the second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_sandpile(grid1, grid2);
	while (is_unstable(grid1))
		print_sandpile(grid1),
		topple_sandpile(grid1, grid2);

}

/**
 * add_sandpile - adds two sandpiles, nulling the 2nd as a buffer
 * @grid1: first sandpile, stores sum
 * @grid2: second sandpile, gets nulled
 */
void add_sandpile(int grid1[3][3], int grid2[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j], grid2[i][j] = 0;
}

/**
 * topple_sandpile - topples a sandpile, dispersing all cells > 3
 * @grid1: the sandpile to topple
 * @grid2: the 'buffer' pile which stores the dispersions
 */
void topple_sandpile(int grid1[3][3], int grid2[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
				(i > 0) ? grid2[i - 1][j] += 1 : 0,
				(j > 0) ? grid2[i][j - 1] += 1 : 0,
				(i < 2) ? grid2[i + 1][j] += 1 : 0,
				(j < 2) ? grid2[i][j + 1] += 1 : 0,
				grid1[i][j] -= 4;
	add_sandpile(grid1, grid2);
}

/**
 * is_unstable - checks if sandpile is unstable
 * @grid: the sandpile to check
 * Return: 1 if unstable else 0
 */
int is_unstable(int grid[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (1);
	return (0);
}

/**
 * print_sandpile - prints the sandpile
 * @grid: the sandpile to print
 */
void print_sandpile(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
