class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n,m = len(grid),len(grid[0])
        q = deque()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    q.append([i,j,0])
        time = 0
        di = [-1,0,1,0,-1]
        while q:
            x,y,d = q.popleft()
            time = max(time,d)
            for i in range(4):
                dx = di[i]+x
                dy = di[i+1]+y
                if dx < 0 or dy < 0 or dx >= n or dy >= m or grid[dx][dy] != 1:
                    continue
                grid[dx][dy] = 2
                q.append([dx,dy,d+1])
        
        for _ in grid:
            if 1 in _:
                return -1
        return time
