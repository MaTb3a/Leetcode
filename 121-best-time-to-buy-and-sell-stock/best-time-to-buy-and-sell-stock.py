class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return (max(x - cur for x,cur in zip(prices,accumulate(prices, min))))