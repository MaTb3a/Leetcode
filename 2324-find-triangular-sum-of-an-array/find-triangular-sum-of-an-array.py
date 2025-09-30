class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        while len(nums) > 1:
            lst = []
            for i in range(1,len(nums)):
                lst.append((nums[i]+nums[i-1])%10)
            nums = lst
        return nums[0]
