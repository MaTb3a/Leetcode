class Solution:
    def mySqrt(self, x: int) -> int:
        if not x :return x
        ans = 1
        for i in range(1,x):
            if i * i <= x:
                ans = i
            else:
                return ans
        return ans