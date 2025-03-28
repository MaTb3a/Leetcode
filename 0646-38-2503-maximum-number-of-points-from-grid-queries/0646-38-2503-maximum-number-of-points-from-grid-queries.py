import heapq

class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        n, m = len(grid), len(grid[0])
        query_indices = sorted([(q, i) for i, q in enumerate(queries)])
        heap = [(grid[0][0], 0, 0)]
        grid[0][0] = 0
        directions = [(1,0), (0,1), (-1,0), (0,-1)]
        ans = [0] * len(queries)
        cnt = 0
        
        for q, idx in query_indices:
            while heap and heap[0][0] < q:
                val, x, y = heapq.heappop(heap)
                cnt += 1
                
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    
                    if 0 <= nx < n and 0 <= ny < m and grid[nx][ny]:
                        heapq.heappush(heap, (grid[nx][ny], nx, ny))
                        grid[nx][ny] = 0
            
            ans[idx] = cnt
        
        return ans