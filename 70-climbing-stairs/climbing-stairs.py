class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 3:
            return n
        step1,step2 = 1,2
        ans = 0
        for i in range(3,n+1):
            ans = step1+step2
            step1 = step2
            step2 = ans
        return ans