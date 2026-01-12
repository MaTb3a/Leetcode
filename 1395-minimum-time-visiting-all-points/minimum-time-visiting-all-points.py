class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        def best(a,b):
            return max(abs(a[0]-b[0]),abs(a[1]-b[1]))
        ans = 0
        for i in range(1,len(points)):
            ans+=best(points[i-1],points[i])
        return ans

