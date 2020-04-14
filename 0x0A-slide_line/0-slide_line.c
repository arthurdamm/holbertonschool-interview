#include "slide_line.h"

/**
 * slide_line - slides a line of ints left or right
 * @line: array of ints
 * @size: size of array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 on success else 0 on error
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		move_zeroes_left(line, size);
		merge_left(line, size);
		move_zeroes_left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		move_zeroes_right(line, size);
		merge_right(line, size);
		move_zeroes_right(line, size);
	}
	return (1);
	(void)line;
	(void)size;
	(void)direction;
}

/**
 * move_zeroes_left - moves all zeroes as if sliding left
 * @line: array of ints
 * @size: size of array
 * Return: 1 on success else 0 on error
 */
int move_zeroes_left(int *line, size_t size)
{
	size_t i = 0, zeroes = 0;

	for (i = 0; i < size; i++)
	{
		if (!line[i])
			zeroes++;
		else if (zeroes)
			line[i - zeroes] = line[i];
	}
	for (i = size - zeroes; i < size; i++)
		line[i] = 0;
	return (1);
}

/**
 * merge_left - merges pairs of same numbers to the left
 * @line: array of ints
 * @size: size of array
 * Return: 1 on success else 0 on error
 */
int merge_left(int *line, size_t size)
{
	size_t i = 0, merges = 0;

	for (i = 1; i < size; i++)
	{
		if (line[i] == line[i - 1])
		{
			merges++;
			line[i - 1] *= 2;
			line[i] = 0;
		}
	}
	return (1);
}

/**
 * move_zeroes_right - moves all zeroes as if sliding right
 * @line: array of ints
 * @size: size of array
 * Return: 1 on success else 0 on error
 */
int move_zeroes_right(int *line, size_t size)
{
	ssize_t i = 0, zeroes = 0;

	for (i = size - 1; i >= 0; i--)
	{
		if (!line[i])
			zeroes++;
		else if (zeroes)
			line[i + zeroes] = line[i];
	}
	for (i = zeroes - 1; i >= 0; i--)
		line[i] = 0;
	return (1);
}

/**
 * merge_right - merges pairs of same numbers to the left
 * @line: array of ints
 * @size: size of array
 * Return: 1 on success else 0 on error
 */
int merge_right(int *line, size_t size)
{
	ssize_t i = 0, merges = 0;

	for (i = size - 2; i >= 0; i--)
	{
		if (line[i] == line[i + 1])
		{
			merges++;
			line[i + 1] *= 2;
			line[i] = 0;
		}
	}
	return (1);
}
