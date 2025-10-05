class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n,m = len(heights),len(heights[0])
        visp = [[0 for _ in range(m)] for _ in range(n)] 
        visa = [[0 for _ in range(m)] for _ in range(n)] 
        
        def valid(x,y):
            return x >= 0 and y >= 0 and x < n and y < m
        
        dr = [-1,0,1,0,-1]
        def pacific_bfs():
            q = deque()
            for i in range(n):
                q.append([i,0])
                visp[i][0] = 1
            for j in range(m):
                q.append([0,j])
                visp[0][j] = 1
            while len(q):
                x,y = q.popleft()
                for i in range(4):
                    dx = dr[i]+x
                    dy = dr[i+1]+y
                    if valid(dx,dy) and visp[dx][dy] == 0 and heights[dx][dy] >= heights[x][y]:
                        visp[dx][dy] = 1
                        q.append([dx,dy])
        
        def atlantic_bfs():
            q = deque()
            for i in range(n):
                q.append([i,m-1])
                visa[i][m-1] =1
            for j in range(m):
                q.append([n-1,j])
                visa[n-1][j] = 1
            while len(q):
                x,y = q.popleft()
                for i in range(4):
                    dx = dr[i]+x
                    dy = dr[i+1]+y
                    if valid(dx,dy) and visa[dx][dy] == 0 and heights[dx][dy] >= heights[x][y]:
                        visa[dx][dy] =1
                        q.append([dx,dy])

        pacific_bfs()
        atlantic_bfs()
        ans = []
        for i in range(n):
            for j in range(m):
                if visa[i][j] and visp[i][j]:
                    ans.append([i,j])
        return ans