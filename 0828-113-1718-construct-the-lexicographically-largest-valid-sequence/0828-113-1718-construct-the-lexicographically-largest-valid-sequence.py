class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        
        def solve(idx,n,vis,v):
            if idx == len(v):
                return True
            if v[idx] != 0:
                return solve(idx+1,n,vis,v)
            for i in range(n,0,-1):
                if vis[i] == True:
                    continue
                nxt = idx
                if i >1:
                    nxt+=i
                if nxt >= 2*n-1 or v[nxt] != 0:
                    continue
                vis[i] = True
                v[idx] = v[nxt] = i
                if solve(idx+1,n,vis,v) == True:
                    return True
                vis[i] = False
                v[idx] = v[nxt] = 0
            return False
        v = [0]*(2*n-1)
        vis = [False] *(n+1)
        solve(0,n,vis,v)
        return v