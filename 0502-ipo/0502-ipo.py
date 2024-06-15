class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        n = len(profits)
        pr = [(capital[i], profits[i]) for i in range(n)]
        pr.sort()
        mx = []
        i = 0
        for x in range(k):
            while i < n and pr[i][0] <= w:
                heapq.heappush(mx, -pr[i][1])
                i += 1
            if not mx:
                break
            w -= heapq.heappop(mx)

        return w