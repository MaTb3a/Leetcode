class Solution:
    dx = [0,0,1,-1]
    dy = [1,-1,0,0]
    def dfs(self,grid,x,y,vis,n,m):
        vis[x][y] = True
        for i in range(0,4):
            ddx = self.dx[i]+x
            ddy = self.dy[i]+y
            if ddx >= 0 and ddy >= 0 and ddx < n and ddy < m and not vis[ddx][ddy] and grid[ddx][ddy]=="1":
                self.dfs(grid,ddx,ddy,vis,n,m)
        

        
    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])
        vis = [[False for i in range(0,m)] for j in range(0,n)]
        print(vis)
        cnt = 0
        for i in range(0,n):
            for j in range(0,m):
                if not vis[i][j] and grid[i][j] == "1":
                    cnt+=1
                    self.dfs(grid,i,j,vis,n,m)
        return cnt