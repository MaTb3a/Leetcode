from typing import List

class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        for i in range(n):
            if grid[i][0] == 0:
                for j in range(m):
                    grid[i][j] = 1 - grid[i][j]
        
        for j in range(m):
            count_ones = sum(grid[i][j] for i in range(n))
            if count_ones < n / 2:
                for i in range(n):
                    grid[i][j] = 1 - grid[i][j]

        total_score = 0
        for i in range(n):
            row_value = int(''.join(map(str, grid[i])), 2)
            total_score += row_value
        
        return total_score
