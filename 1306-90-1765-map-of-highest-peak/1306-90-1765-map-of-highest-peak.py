from collections import deque

class Solution:
    def highestPeak(self, isWater: list[list[int]]) -> list[list[int]]:
        n, m = len(isWater), len(isWater[0])
        visited = [[False] * m for _ in range(n)]
        q = deque()
        
        for i in range(n):
            for j in range(m):
                if isWater[i][j] == 1:
                    isWater[i][j] = 0
                    q.append((i, j))
                    visited[i][j] = True
        
        directions = [-1, 0, 1, 0, -1]
        
        while q:
            x, y = q.popleft()
            for i in range(4):
                dx, dy = x + directions[i], y + directions[i + 1]
                if 0 <= dx < n and 0 <= dy < m and not visited[dx][dy]:
                    visited[dx][dy] = True
                    isWater[dx][dy] = isWater[x][y] + 1
                    q.append((dx, dy))
        
        return isWater
