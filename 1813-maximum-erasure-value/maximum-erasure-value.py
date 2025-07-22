class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        r,ans,s =0,0,0
        mp = defaultdict()
        for l in range(len(nums)):
            while r < len(nums) and nums[r] not in mp:
                mp[nums[r]] = 1
                s+=nums[r]
                r+=1
            ans=max(ans,s)
            s-=nums[l]
            del mp[nums[l]]
        return ans
