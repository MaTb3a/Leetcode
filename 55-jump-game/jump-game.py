class Solution:
    def canJump(self, nums: List[int]) -> bool:
        mx = nums[0]
        for i in range(1,len(nums)):
            if mx >= i:
                mx=max(mx,i+nums[i])
        return mx >= len(nums)-1
        