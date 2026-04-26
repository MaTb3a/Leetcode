class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        for i in range(31,-1,-1):
            if n%2 == 1:
                ans += 1<<i
            n = n //2
        return ans
       