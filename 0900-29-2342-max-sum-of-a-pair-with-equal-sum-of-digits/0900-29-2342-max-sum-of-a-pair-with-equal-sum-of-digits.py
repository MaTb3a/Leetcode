class Solution:
    def maximumSum(self, nums):
        ans = -1
        mp = {}

        for x in nums:
            digit_sum = sum(map(int, str(x)))
            if digit_sum in mp:
                ans = max(ans, mp[digit_sum] + x)
                mp[digit_sum] = max(mp[digit_sum], x)
            else:
                mp[digit_sum] = x

        return ans
