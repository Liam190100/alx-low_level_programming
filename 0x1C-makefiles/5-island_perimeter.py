#!/usr/bin/python3

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    Args:
    grid (List[List[int]]): of island.

    Returns:
    int: The perimeter of the island.

    Constraints:
    - Grid is a list of list of integers.
    - 0 represents a water zone.
    - 1 represents a land zone.
    - Grid cells are connected horizontally/vertically (not diagonally).
    - Grid is rectangular, width and height don't exceed 100.
    - Grid is completely surrounded by water, and there is one island (or nothing).
    - The island doesn't have "lakes" (water inside that isn't connected to the water around the island).
    """
    if not grid:
        return (0)

    perimeter = 0
    rows, columns = len(grid), len(grid[0])

    for i in range(rows):
        for j in range(columns):
            if grid[i][j] == 1:
                perimeter += 4  # Start with 4 sides of the current cell

                # Check the neighboring cells (up, down, left, right)
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2  # Subtract 2 for the shared edge
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2  # Subtract 2 for the shared edge

    return (perimeter)
