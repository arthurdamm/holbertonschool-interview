#!/usr/bin/python3
"""
Island Perimeter Algo
O(n) time O(1) space
"""


def island_perimeter(grid):
    """Finds water to call DFS method"""

    def dfs(row, col):
        """ Uses DFS to calculate permeter"""
        if not 0 <= row < len(grid) or not 0 <= col < len(grid[row]) or \
           grid[row][col] != 1:
            return 0
        grid[row][col] = -1
        perimeter = 0
        for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            if not 0 <= row + dr <= len(grid) or not 0 <= col < len(grid[row])\
               or grid[row + dr][col + dc] == 0:
                perimeter += 1
        for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            perimeter += dfs(row + dr, col + dc)
        return perimeter
    perimeter = 0
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                perimeter = dfs(row, col)
    return perimeter
