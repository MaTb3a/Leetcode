class Solution:
    
    def solve(self,i,j,grid,n,dp):
        if i == n:
            return 0
        if dp[i][j] != 1000000:
            return dp[i][j]
        ret = 1000000
        for k in range(0,len(grid)):
            if j != k:
                ret=min(ret,self.solve(i+1,k,grid,n,dp)+grid[i][k])
        dp[i][j] = ret
        return ret
    
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        ans = 1000000
        n = len(grid)
        dp = [[1000000 for _ in range(0,n+1)] for _ in range(0,n+1)]
        for i in range(0,len(grid)):
            ans=min(ans,self.solve(1,i,grid,n,dp)+grid[0][i])
        return ans