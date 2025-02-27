from typing import List

class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        n = len(arr)
        dp = [[0] * n for _ in range(n)]
        mp = {x: i for i, x in enumerate(arr)}
        ans = 0

        for i in range(n):
            for j in range(i + 1, n):
                next_val = arr[i] + arr[j]
                if next_val in mp:
                    next_idx = mp[next_val]
                    dp[j][next_idx] = dp[i][j] + 1
                    ans = max(ans, dp[j][next_idx])

        return ans + 2 if ans > 0 else 0