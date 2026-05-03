class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # sort 
        nums.sort()
        for i in range(1,len(nums),2):
            if nums[i] != nums[i-1]:
                return nums[i-1]
        return nums[-1]