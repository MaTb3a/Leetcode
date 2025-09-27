class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        def solve(p1, p2, p3):
            x1, y1 = p1
            x2, y2 = p2
            x3, y3 = p3
            area = 0.5 * abs((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1))
            return area

        ans = 0
        for i in range(2,len(points)):
            for j in range(1,i):
                for k in range(j):
                    ans=max(ans,solve(points[i],points[j],points[k]))
        return ans
