from collections import deque

class Solution:
    def minimumObstacles(self, grid):
        n, m = len(grid), len(grid[0])
        dist = [float('inf')] * (n * m)
        dx = [0, 1, 0, -1, 0] 
        q = deque([(0, 0)])  
        
        dist[0] = 0
        while q:
            d, idx = q.popleft()
            i, j = divmod(idx, m)
            if i == n - 1 and j == m - 1:
                return d
            
            for a in range(4):
                r, c = i + dx[a], j + dx[a + 1]
                if 0 <= r < n and 0 <= c < m:
                    d2 = d + grid[r][c]
                    idx2 = r * m + c
                    if d2 < dist[idx2]:
                        dist[idx2] = d2
                        if grid[r][c] == 0:
                            q.appendleft((d2, idx2))
                        else:
                            q.append((d2, idx2))
        
        return -1
