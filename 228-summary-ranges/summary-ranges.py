class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        
        i,j,n = 0,1,len(nums)
        
        ans = []
        while j < n:
            if nums[j] == nums[j-1]+1:
                j+=1
            else:
                if nums[i] == nums[j-1]:
                    ans.append(str(nums[i]))
                else:
                    ans.append(str(nums[i])+"->"+str(nums[j-1]))
                i =j
                j+=1
        if len(nums):
            if nums[i] == nums[j-1]:
                ans.append(str(nums[i]))
            else:
                ans.append(str(nums[i])+"->"+str(nums[j-1]))

        return ans
        

