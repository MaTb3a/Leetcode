from collections import defaultdict

class Solution:
    def countBadPairs(self, nums):
        n = len(nums)
        bads = n * (n - 1) // 2
        mp = defaultdict(int)
        for i in range(n):
            bads -= mp[nums[i] - i]
            mp[nums[i] - i] += 1

        return bads
