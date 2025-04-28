class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ans,cur_sum,l = 0,0,0
        for r in range(len(nums)):
            cur_sum+=nums[r]
            while cur_sum*(r-l+1) >= k:
                cur_sum-=nums[l]
                l+=1
            ans+=(r-l+1)
        return ans