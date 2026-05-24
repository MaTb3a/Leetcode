class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2 :
            return x
        ans = 0
        for i in range(1,x):
            if i*i <= x:
                ans = i
            else:
                break
        return ans
            