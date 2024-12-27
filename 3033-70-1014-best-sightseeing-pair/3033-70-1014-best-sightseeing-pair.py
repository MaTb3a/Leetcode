class Solution:
    def maxScoreSightseeingPair(self, values: list[int]) -> int:
        n = len(values)
        mx = 0
        dp = values[0]
        for j in range(1, n):
            mx = max(mx, values[j] - j + dp)
            dp = max(dp, values[j] + j)
        return mx
