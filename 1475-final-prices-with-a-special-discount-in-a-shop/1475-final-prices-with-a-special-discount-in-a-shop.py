class Solution:
    def finalPrices(self, prices: list[int]) -> list[int]:
        n = len(prices)
        stack = []
        for i in range(n - 1, -1, -1):
            while stack and stack[-1] > prices[i]:
                stack.pop()
            tmp = prices[i]
            if stack:
                prices[i] -= stack[-1]
            stack.append(tmp)
        return prices
