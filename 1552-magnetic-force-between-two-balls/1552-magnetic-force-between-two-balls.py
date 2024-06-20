class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        def ok(x):
            cnt = 0
            lst = -1e9
            for i in range(len(position)):
                if position[i] - lst >= x:
                    cnt+=1
                    lst = position[i]
            return cnt >= m
        l = 1
        r = 1e9
        cur = -1
        while l <= r:
            md = int((r+l)//2)
            if ok(md):
                l = md +1
                cur = md
            else:
                r = md-1
        return cur