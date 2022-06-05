class Solution:
    def totalNQueens(self, n: int) -> int:
        d1 = set()
        d2 = set()
        col = set()
        def backtrack(r,n) -> int:
            if(r==n):
                return 1
            ret=0
            for c in range(0,n):
                if (c not in col and (r+c) not in d1 and (r-c) not in d2):
                    col.add(c)
                    d1.add(r+c)
                    d2.add(r-c)
                    ret+=backtrack(r+1,n)
                    col.remove(c)
                    d1.remove(r+c)
                    d2.remove(r-c)
            return ret
    
        return backtrack(0,n)
    
   
            