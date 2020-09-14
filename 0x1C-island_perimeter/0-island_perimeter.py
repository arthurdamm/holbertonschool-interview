#!/usr/bin/python3
"""
Island Perimeter Algo
O(n) time O(1) space
"""


def island_perimeter(grid):
    """Looks up and left to subtract water"""
    perimeter = 0
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                perimeter += 4
                if row and grid[row - 1][col] == 1:
                    perimeter -= 2
                if col and grid[row][col - 1] == 1:
                    perimeter -= 2
    return perimeter
