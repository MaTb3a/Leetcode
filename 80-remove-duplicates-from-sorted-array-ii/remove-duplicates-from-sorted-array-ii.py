class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        j = 1
        k = 0 
        for i in range(1,len(nums)):
            if nums[i] != nums[j-1] or k-1 < 0 or nums[i] != nums[k-1]:
                nums[j] = nums[i]
                k+=1
                j+=1

                
        return j