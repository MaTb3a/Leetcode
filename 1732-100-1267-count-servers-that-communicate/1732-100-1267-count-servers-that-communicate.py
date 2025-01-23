class Solution:
    def countServers(self, grid):
        n, m = len(grid), len(grid[0])
        row = [0] * n
        col = [0] * m
        cnt = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    row[i] += 1
                    col[j] += 1

        for i in range(n):
            for j in range(m):
                if grid[i][j] and (row[i] > 1 or col[j] > 1):
                    cnt += 1

        return cnt
