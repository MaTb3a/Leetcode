class Solution:
    def dfs(self, x, y, grid, m, n, direction):
        if x < 0 or y < 0 or x >= m or y >= n or grid[x][y] > 1:
            return
        grid[x][y] = 1
        if direction == 'U':
            self.dfs(x - 1, y, grid, m, n, direction)
        if direction == 'D':
            self.dfs(x + 1, y, grid, m, n, direction)
        if direction == 'R':
            self.dfs(x, y + 1, grid, m, n, direction)
        if direction == 'L':
            self.dfs(x, y - 1, grid, m, n, direction)

    def countUnguarded(self, m, n, guards, walls):
        grid = [[0] * n for _ in range(m)]

        for wall in walls:
            grid[wall[0]][wall[1]] = 2
        for guard in guards:
            grid[guard[0]][guard[1]] = 3

        for guard in guards:
            self.dfs(guard[0] - 1, guard[1], grid, m, n, 'U')
            self.dfs(guard[0] + 1, guard[1], grid, m, n, 'D')
            self.dfs(guard[0], guard[1] + 1, grid, m, n, 'R')
            self.dfs(guard[0], guard[1] - 1, grid, m, n, 'L')

        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    count += 1

        return count
