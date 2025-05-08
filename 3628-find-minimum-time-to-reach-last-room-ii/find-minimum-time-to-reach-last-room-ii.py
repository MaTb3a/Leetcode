class Solution:
    def minTimeToReach(self, moveTime):
        n = len(moveTime)
        m = len(moveTime[0])
        q = []
        ans = [[float("inf")] * m for _ in range(n)]
        heapq.heappush(q, (0, 0, 0,0))  
        d = [-1, 0, 1, 0, -1]
        ans[0][0] = 0
        while q:
            dist, x, y,step = heapq.heappop(q)
            for i in range(4):
                dx = d[i] + x
                dy = d[i + 1] + y
                if 0 <= dx < n and 0 <= dy < m:
                    curDist = max(ans[x][y], moveTime[dx][dy])+(step+1)
                    if ans[dx][dy] > curDist:
                        ans[dx][dy] = curDist
                        heapq.heappush(q, (curDist, dx, dy,not step))
        return ans[n - 1][m - 1]



