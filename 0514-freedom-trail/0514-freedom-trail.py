class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        n = len(ring)
        m = len(key)
        @functools.lru_cache(None)
        def solve(i,j):
            if j == m:
                return 0
            ret = 1000000
            for k,ch in enumerate(ring):
                if ch == key[j]:
                    minDist = min(abs(i-k),n-abs(i-k))
                    ret=min(ret,solve(k,j+1)+minDist)
            return ret
        return solve(0,0)+m