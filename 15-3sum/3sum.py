class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        for i in range(0,len(nums)):
            if i and nums[i] == nums[i-1]:
                continue
            j,k = i+1,len(nums)-1
            goal = -nums[i]
            while j < k:
                cur = nums[i]+nums[j]+nums[k]
                if cur == 0:
                    ans.append([nums[i],nums[j],nums[k]])
                    k-=1
                    while j < k and nums[k] == nums[k+1]:
                        k-=1
                if cur > 0:
                    k-=1
                else:             
                    j+=1
        return ans
        # -4,-1,-1,0,1,2
                
