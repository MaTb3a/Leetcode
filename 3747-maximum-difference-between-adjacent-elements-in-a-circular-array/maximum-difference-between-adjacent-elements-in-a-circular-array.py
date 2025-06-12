class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        mx = -200
        for i in range(1,len(nums)):
            mx = max(mx,abs(nums[i] - nums[i-1]))
        return max(mx,abs(nums[-1]-nums[0]))
