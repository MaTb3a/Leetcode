import heapq

class Solution:
    def leftmostBuildingQueries(self, heights: list[int], queries: list[list[int]]) -> list[int]:
        n = len(heights)
        m = len(queries)
        v = [[] for _ in range(n)]
        ans = [-1] * m

        for i in range(m):
            x, y = queries[i]
            if x > y:
                x, y = y, x
            if x == y or heights[x] < heights[y]:
                ans[i] = y
            else:
                v[y].append((max(heights[x], heights[y]), i))

        pr = []
        for i in range(n):
            for it in v[i]:
                heapq.heappush(pr, it)
            while pr and pr[0][0] < heights[i]:
                ans[heapq.heappop(pr)[1]] = i

        return ans
