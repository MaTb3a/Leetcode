class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        i,j,sm,ans = 0,0,0,1e9

        for j in range(len(nums)):
            sm+=nums[j]
            while sm >= target: # yes -> No
                ans = min(ans,j-i+1)
                sm -= nums[i]
                i+=1
        
        return ans if ans != 1e9 else 0 


