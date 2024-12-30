class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        mod = int(1e9 + 7)
        dp = [0] * (high + 1)
        
        for i in range(low, high + 1):
            dp[i] = 1

        for i in range(high, -1, -1):
            if i + zero <= high:
                dp[i] += dp[i + zero]
            if i + one <= high:
                dp[i] += dp[i + one]
            dp[i] %= mod
        
        return dp[0]
