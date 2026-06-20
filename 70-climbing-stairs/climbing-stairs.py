class Solution:
    @cache
    def climbStairs(self, n: int) -> int:
        if n < 2:
            return 1
        return self.climbStairs(n-1) + self.climbStairs(n-2)