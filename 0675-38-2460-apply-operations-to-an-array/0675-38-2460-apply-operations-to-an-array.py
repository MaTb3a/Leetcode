class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        j = 0
        for i in range(0,len(nums)):
            if i+1 < len(nums) and nums[i] == nums[i+1] and nums[i] > 0:
                x = nums[i]
                nums[i] = nums[i+1] = 0
                nums[j] = x*2
                j+=1
            elif nums[i] > 0:
                nums[i],nums[j] = nums[j],nums[i]
                j+=1
        return nums