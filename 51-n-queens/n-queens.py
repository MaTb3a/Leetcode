class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        grid = [['.' for _ in range(0,n)] for _ in range(0,n)]
        ans = []
        col = [0]*n
        dig1 = [0]*2*n
        dig2 = [0]*2*n

        def solve(i,grid):
            if i == n:
                a = []
                ans.append([''.join(r) for r in grid])
                return
            for j in range(0,n):
                if col[j] == 0 and dig1[i-j+n] == 0 and dig2[i+j] == 0:
                    col[j] = dig1[i-j+n] = dig2[i+j] = 1
                    grid[i][j] = 'Q'
                    solve(i+1,grid)
                    grid[i][j] = '.'
                    col[j] = dig1[i-j+n] = dig2[i+j] = 0
        solve(0,grid)
        return ans

        

