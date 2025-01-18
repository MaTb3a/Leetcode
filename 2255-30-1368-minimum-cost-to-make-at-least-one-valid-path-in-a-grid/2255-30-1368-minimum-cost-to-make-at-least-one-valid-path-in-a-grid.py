from collections import deque

class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dx = [0, 0, 1, -1]
        dy = [1, -1, 0, 0]
        dist = [[float('inf')] * m for _ in range(n)]
        dist[0][0] = 0
        q = deque([(0, 0)])
        
        while q:
            x, y = q.popleft()
            for i in range(4):
                ddx, ddy = x + dx[i], y + dy[i]
                if 0 <= ddx < n and 0 <= ddy < m:
                    new_cost = dist[x][y] + (grid[x][y] != i + 1)
                    if dist[ddx][ddy] > new_cost:
                        dist[ddx][ddy] = new_cost
                        q.append((ddx, ddy))
        
        return dist[n - 1][m - 1]
