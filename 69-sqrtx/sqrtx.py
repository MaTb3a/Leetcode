class Solution:
    def mySqrt(self, x: int) -> int:
        l,r,ans = 0,x,-1
        while l <= r:
            md = (l+r)//2
            if md * md <= x:
                ans = md
                l = md+1
            else:
                r = md -1
        return ans