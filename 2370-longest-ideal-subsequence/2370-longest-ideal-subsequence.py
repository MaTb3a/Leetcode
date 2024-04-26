class Solution:
    def solve(self,idx,lst,k,s,dp):
        if idx == len(s):
            return 0
        ret = -10000000000
        if dp[idx][lst] != -1:
            return dp[idx][lst]
        if abs( (ord(s[idx])-ord('a')) - lst) <= k:
            ret=max(ret,self.solve(idx+1,(ord(s[idx])-ord('a')),k,s,dp)+1)
        ret=max(ret,self.solve(idx+1,lst,k,s,dp))
        dp[idx][lst]=ret
        return ret
    def longestIdealString(self, s: str, k: int) -> int:
        # dp = [[-1] for _ in range(0,26)] * for _ in range(0,len(s))
        dp = [[-1] * (26) for _ in range(0,len(s))]
        best = 0
        for i in range(0,len(s)):
            best = max(best,self.solve(i+1,(ord(s[i])-ord('a')),k,s,dp)+1)
        return best