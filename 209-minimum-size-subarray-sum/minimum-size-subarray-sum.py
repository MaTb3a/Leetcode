class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        i,j,sm,n = 0,0,0,1e9

        for j in range(len(nums)):
            sm+=nums[j]
            while i <= j and sm >= target:
                n = min(n,j-i+1)
                sm -= nums[i]
                i+=1
    
        return 0 if n == 1e9 else n
