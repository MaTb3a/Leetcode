class Solution:
    @functools.lru_cache(None)
    def solve(self,i,j,ring,key):
        if j == len(key):
            return 0
        ret = 1000000
        for k,ch in enumerate(ring):
            if ch == key[j]:
                minDist = min(abs(i-k),len(ring)-abs(i-k))
                ret = min(ret,self.solve(k,j+1,ring,key)+minDist)
        return ret

     
    def findRotateSteps(self, ring: str, key: str) -> int:
        dp = [[-1 for _ in range(0,101)] for _ in range(0,101)]
        return self.solve(0,0,ring,key)+len(key)