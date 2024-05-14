class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        row, col=len(grid), len(grid[0]) 
        def solve(i, j, sum):
            if i<0 or i>=row or j<0 or j>=col or grid[i][j]==0:
                return sum
            tmp=grid[i][j]
            sum+=tmp
            grid[i][j]=0
            ans=max(solve(i+1, j, sum), solve(i-1, j, sum), solve(i, j+1, sum), solve(i, j-1, sum))
            grid[i][j]=tmp
            return ans
        gold=0
        for i in range(row):
            for j in range(col):
                if grid[i][j]!=0:
                    gold=max(gold, solve(i, j, 0))
        return gold