class Solution:
    def numWays(self, words: list[str], target: str) -> int:
        mod = int(1e9 + 7)
        n, m = len(target), len(words[0])
        
        # Frequency array for each column of words
        frq = [[0] * 26 for _ in range(m)]
        for word in words:
            for k in range(m):
                frq[k][ord(word[k]) - ord('a')] += 1

        # DP table
        dp = [[0] * (m + 1) for _ in range(2)]
        for k in range(m + 1):
            dp[n & 1][k] = 1

        # Bottom-up calculation
        for i in range(n - 1, -1, -1):
            for k in range(m - 1, -1, -1):
                dp[i & 1][k] = dp[i & 1][k + 1]
                if frq[k][ord(target[i]) - ord('a')]:
                    dp[i & 1][k] += dp[(i + 1) & 1][k + 1] * frq[k][ord(target[i]) - ord('a')]
                    dp[i & 1][k] %= mod
            dp[(i + 1) & 1] = [0] * (m + 1)
        
        return dp[0][0]
