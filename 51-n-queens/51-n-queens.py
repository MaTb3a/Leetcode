class Solution:
   
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans=[[]]
        col=set()
        d1=set()
        d2=set()
        v=[]
        def solve(r):
            if(r==n):
                ans.append(list(v))
                return
            for c in range(0,n):
                if (c not in col and r-c not in d1 and r+c not in d2):
                    col.add(c)
                    d1.add(r-c)
                    d2.add(r+c)
                    s = '.'*n
                    s=list(s);
                    s[c]='Q'
                    v.append("".join(s))
                    solve(r+1)
                    v.pop()
                    col.remove(c)
                    d1.remove(r-c)
                    d2.remove(r+c)
        ans.pop()
        solve(0)
        return ans;