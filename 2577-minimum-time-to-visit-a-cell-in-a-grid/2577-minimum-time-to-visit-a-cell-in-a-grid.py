import heapq

class Solution:
    def minimumTime(self, grid):
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1

        n, m = len(grid), len(grid[0])
        dx = [0, 0, 1, -1]
        dy = [1, -1, 0, 0]
        visited = [[False] * m for _ in range(n)]
        pq = [] 
        heapq.heappush(pq, (0, 0, 0))

        while pq:
            cur_time, x, y = heapq.heappop(pq)
            if x == n - 1 and y == m - 1:
                return cur_time
            if visited[x][y]:
                continue
            visited[x][y] = True

            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                if 0 <= nx < n and 0 <= ny < m:
                    wasted_time = 0 if (grid[nx][ny] - cur_time) % 2 else 1
                    max_time = max(cur_time + 1, grid[nx][ny] + wasted_time)
                    heapq.heappush(pq, (max_time, nx, ny))

        return -1
