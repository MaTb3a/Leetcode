class Solution:
    def mincostTickets(self, days: list[int], costs: list[int]) -> int:
        lst = days[-1]
        dp = [0] * (lst + 1)

        day_set = set(days) 

        for d in range(1, lst + 1):
            if d not in day_set:
                dp[d] = dp[d - 1]
                continue
            ch1 = costs[0] + dp[d - 1]
            ch2 = costs[1] + dp[max(0, d - 7)]
            ch3 = costs[2] + dp[max(0, d - 30)]
            dp[d] = min(ch1, ch2, ch3)

        return dp[lst]
