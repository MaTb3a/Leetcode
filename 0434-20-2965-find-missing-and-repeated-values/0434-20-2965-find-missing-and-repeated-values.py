class Solution:
    def findMissingAndRepeatedValues(self, grid):
        n = len(grid)
        a = 0
        gsum = 0
        for row in grid:
            for x in row:
                nx = abs(x)
                gsum += nx
                r = (nx - 1) // n
                c = (nx - 1) % n
                if grid[r][c] < 0:
                    a = nx
                grid[r][c] *= -1
        n_squared = n * n
        total_sum = n_squared * (n_squared + 1) // 2
        return [a, total_sum - gsum + a]