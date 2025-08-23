class Solution: 

    def minimumSum(self, grid: List[List[int]]) -> int:
        @cache
        def helper(a,b,c,d):
            mii,mij = float('inf'),float('inf')
            mai,maj = -float('inf'),-float('inf')
            for i in range(a,b+1):
                for j in range(c,d+1):
                    if grid[i][j] == 1:
                        mii,mij = min(mii,i),min(mij,j)
                        mai,maj = max(mai,i),max(maj,j)
            return (mai-mii+1)*(maj-mij+1)
        m = len(grid)
        n = len(grid[0])
        res = 99999
        for i in range(m-1):
            for j in range(i+1,m-1):
                res = min(helper(0,i,0,n-1)+helper(i+1,j,0,n-1)+helper(j+1,m-1,0,n-1),res)
        for i in range(n-1):
            for j in range(i+1,n-1):
                res = min(helper(0,m-1,0,i)+helper(0,m-1,i+1,j)+helper(0,m-1,j+1,n-1),res)
        
        for i in range(m-1):
            for j in range(n-1):
                res = min(helper(0,i,0,n-1)+helper(i+1,m-1,0,j)+helper(i+1,m-1,j+1,n-1),res)
                res = min(helper(0,m-1,0,j)+helper(0,i,j+1,n-1)+helper(i+1,m-1,j+1,n-1),res)
                res = min(helper(0,i,0,j)+helper(0,i,j+1,n-1)+helper(i+1,m-1,0,n-1),res)
                res = min(helper(0,i,0,j)+helper(i+1,m-1,0,j)+helper(0,m-1,j+1,n-1),res)               
        return res
        