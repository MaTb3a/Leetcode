class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        v = [0]*(2*n-1)
        vis = set()
        def solve(idx,n):
            if idx == len(v):
                return True
            if v[idx] != 0:
                return solve(idx+1,n)
            for i in range(n,0,-1):
                if i in vis:
                    continue
                nxt = idx
                if i >1:
                    nxt+=i
                if nxt >= 2*n-1 or v[nxt] != 0:
                    continue
                vis.add(i)
                v[idx] = v[nxt] = i
                if solve(idx+1,n) == True:
                    return True
                vis.remove(i)
                v[idx] = v[nxt] = 0
            return False
       
        solve(0,n)
        return v