class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        cur = prices[0]
        ans = 0
        for x in prices:
            ans = max(ans,x-cur)
            cur = min(cur,x)
        return ans