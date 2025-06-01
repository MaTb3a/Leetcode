class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        ans = 0
        for i in range((limit)+1):
            y = min(n-i,limit)
            z = max(0,n-i-y)
            if y >= z:
                ans += y - z+1
        return ans