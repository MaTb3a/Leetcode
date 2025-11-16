class Solution:
    def numSub(self, s: str) -> int:
        def solve(n):
            return n*(n+1)//2
        mod = 1000000007
        cnt,ans =0,0
        for x in s:
            if x == '1':
                cnt+=1
            else:
                ans=(ans+solve(cnt))%mod
                cnt = 0
        return ans+solve(cnt)