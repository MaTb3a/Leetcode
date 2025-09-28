class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
       
        nums.sort()
        for i in range(len(nums)-2,-1,-1):
            j,k = i+1,len(nums)-1
            while( k > j and nums[k] >= nums[i]+nums[j]):
                k-=1
            if k > j:
                return nums[i]+nums[j]+nums[k]
    
        return 0
