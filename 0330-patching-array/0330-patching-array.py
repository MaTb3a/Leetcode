class Solution(object):
    def minPatches(self, nums, n):
        mis = 1
        ans = 0
        idx = 0
        while mis <= n:
            if idx < len(nums) and nums[idx] <= mis:
                mis += nums[idx]
                idx += 1
            else:
                mis += mis
                ans += 1

        return ans