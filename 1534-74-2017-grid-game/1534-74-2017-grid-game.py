class Solution:
    def gridGame(self, grid):
        b = sum(grid[0])
        a = 0
        ans = float('inf')
        
        for i in range(len(grid[0])):
            b -= grid[0][i]
            ans = min(ans, max(a, b))
            a += grid[1][i]
        
        return ans
