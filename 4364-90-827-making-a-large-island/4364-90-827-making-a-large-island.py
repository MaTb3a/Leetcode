class Solution:
    def largestIsland(self, grid):
        n = len(grid)
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        def dfs(x, y, island_id):
            if x < 0 or y < 0 or x >= n or y >= n or grid[x][y] != 1:
                return 0
            grid[x][y] = island_id
            size = 1
            for dx, dy in directions:
                size += dfs(x + dx, y + dy, island_id)
            return size

        island_sizes = {}
        island_id = 2
        max_island = 0

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    island_sizes[island_id] = dfs(i, j, island_id)
                    max_island = max(max_island, island_sizes[island_id])
                    island_id += 1

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    unique_islands = set()
                    for dx, dy in directions:
                        ni, nj = i + dx, j + dy
                        if 0 <= ni < n and 0 <= nj < n and grid[ni][nj] > 1:
                            unique_islands.add(grid[ni][nj])
                    
                    new_size = 1 + sum(island_sizes[iid] for iid in unique_islands)
                    max_island = max(max_island, new_size)

        return max_island
