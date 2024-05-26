class Solution:
    def checkRecord(self, n: int) -> int:
        # A 0
        # L 1
        # P 2
        mod = 1000000007
        memo = [[[-1] * 3 for _ in range(4)] for _ in range(n + 1)]
        def solve(idx,cntLate,absence):
            if cntLate >= 3 or absence >= 2:
                return 0
            if idx == n:
                return 1
            if memo[idx][cntLate][absence] != -1:
                return memo[idx][cntLate][absence]
            
            ret = solve(idx+1,0,absence+1)
            ret = (ret + solve(idx+1,cntLate+1,absence))%mod
            ret = (ret + solve(idx+1,0,absence))%mod
            memo[idx][cntLate][absence] = ret
            return ret
        return solve(0,0,0)%mod