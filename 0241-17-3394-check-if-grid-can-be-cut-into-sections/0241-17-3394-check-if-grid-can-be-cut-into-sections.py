class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        def check(rectangles,d):
            rectangles.sort(key=lambda rectangles:rectangles[d])

            cnt,mx = 0 ,rectangles[0][d+2]
            for i in range(1,len(rectangles)):
                if mx <= rectangles[i][d]:
                    cnt+=1
                mx = max(mx,rectangles[i][d+2])
            return cnt >= 2
        
        return check(rectangles,0) or check(rectangles,1)