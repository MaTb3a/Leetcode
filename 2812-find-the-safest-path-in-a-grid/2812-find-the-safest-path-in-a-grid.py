class Solution:

    dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)

        multi_source_queue = deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    multi_source_queue.append((i, j))
                    grid[i][j] = 0
                else:
                    grid[i][j] = -1

        while multi_source_queue:
            size = len(multi_source_queue)
            while size > 0:
                curr = multi_source_queue.popleft()
                for d in self.dir:
                    di, dj = curr[0] + d[0], curr[1] + d[1]
                    val = grid[curr[0]][curr[1]]
                    if self.isValidCell(grid, di, dj) and grid[di][dj] == -1:
                        grid[di][dj] = val + 1
                        multi_source_queue.append((di, dj))
                size -= 1

        start, end, res = 0, 0, -1
        for i in range(n):
            for j in range(n):
                end = max(end, grid[i][j])

        while start <= end:
            mid = start + (end - start) // 2
            if self.isValidSafeness(grid, mid):
                res = mid
                start = mid + 1
            else:
                end = mid - 1

        return res
    
    def isValidCell(self, grid, i, j) -> bool:
        n = len(grid)
        return 0 <= i < n and 0 <= j < n

    def isValidSafeness(self, grid, min_safeness) -> bool:
        n = len(grid)

        if grid[0][0] < min_safeness or grid[n - 1][n - 1] < min_safeness:
            return False

        traversal_queue = deque([(0, 0)])
        visited = [[False] * n for _ in range(n)]
        visited[0][0] = True

        while traversal_queue:
            curr = traversal_queue.popleft()
            if curr[0] == n - 1 and curr[1] == n - 1:
                return True  # Valid path found

            for d in self.dir:
                di, dj = curr[0] + d[0], curr[1] + d[1]
                if self.isValidCell(grid, di, dj) and not visited[di][dj] and grid[di][dj] >= min_safeness:
                    visited[di][dj] = True
                    traversal_queue.append((di, dj))

        return False  # No valid path found