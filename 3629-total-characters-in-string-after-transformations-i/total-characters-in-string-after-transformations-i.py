class Solution(object):
    def lengthAfterTransformations(self, s, t):
        mod = 10**9 + 7
        dp = [0] * (t + 26)
        for i in range(26): dp[i] = 1
        for i in range(26, t + 26): dp[i] = (dp[i - 26] + dp[i - 25]) % mod
        ans = 0
        for ch in s: ans = (ans + dp[ord(ch) - ord('a') + t]) % mod
        return ans