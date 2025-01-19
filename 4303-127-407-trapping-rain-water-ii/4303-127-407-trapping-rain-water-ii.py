import heapq

class Solution:
    def trapRainWater(self, heightMap: list[list[int]]) -> int:
        n, m = len(heightMap), len(heightMap[0])
        visited = [[False] * m for _ in range(n)]
        pq = []
        
        for i in range(n):
            for j in range(m):
                if i == 0 or j == 0 or i == n - 1 or j == m - 1:
                    heapq.heappush(pq, (heightMap[i][j], i, j))
                    visited[i][j] = True
        
        ans = 0
        level = 0
        directions = [-1, 0, 1, 0, -1]
        
        while pq:
            height, x, y = heapq.heappop(pq)
            level = max(level, height)
            for i in range(4):
                nx, ny = x + directions[i], y + directions[i + 1]
                if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
                    visited[nx][ny] = True
                    ans += max(0, level - heightMap[nx][ny])
                    heapq.heappush(pq, (heightMap[nx][ny], nx, ny))
        
        return ans
