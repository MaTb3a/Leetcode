class Solution:
    def minEnd(self, n: int, x: int) -> int:
        ans,steps = x,n-1
        idx = 1
        while steps > 0 :
            if (x & idx) == 0:
                ans |= (steps&1) * idx
                steps>>=1
            idx<<=1
        return ans