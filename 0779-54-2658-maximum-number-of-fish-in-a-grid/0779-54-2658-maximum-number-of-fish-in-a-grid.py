class Solution:
    def DFS(self, x, y, grid):
        if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[0]) or grid[x][y] == 0:
            return 0
        ans = grid[x][y]
        grid[x][y] = 0
        return (
            ans
            + self.DFS(x + 1, y, grid)
            + self.DFS(x - 1, y, grid)
            + self.DFS(x, y + 1, grid)
            + self.DFS(x, y - 1, grid)
        )

    def findMaxFish(self, grid):
        mx = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] > 0:
                    mx = max(mx, self.DFS(i, j, grid))
        return mx
