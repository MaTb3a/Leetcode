class Solution:
    def countCommas(self, n: int) -> int:
        base = 1000
        ans = 0
        while base <= n:
            ans+=n - base +1
            base*=1000
        return ans


    
    