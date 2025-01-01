class Solution:
    def maxScore(self, s: str) -> int:
        zeros = 0
        ones = s.count('1')
        ans = 0

        for ch in s[:-1]:
            if ch == '1':
                ones -= 1
            else:
                zeros += 1
            ans = max(ans, ones + zeros)

        return ans
