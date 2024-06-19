class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        def BS(x):
            cnt = 0
            curLen = 0
            for i in range(n):
                if bloomDay[i] <= x:
                    curLen+=1
                else:
                    curLen = 0
                if curLen == k:
                    curLen = 0
                    cnt+=1
            if curLen >= k:
                cnt+=1
            return cnt>= m
      
        n = len(bloomDay)
        l = 1
        r = 1e9
        cur = -1
        while l <= r:
            md =int ((l+r)//2)
            if BS(md):
                cur = md
                r = md -1
            else:
                l = md+1
        return cur
                
                