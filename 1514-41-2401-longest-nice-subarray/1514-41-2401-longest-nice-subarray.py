class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        l,ans,mask=0,0,0
        for r in range(len(nums)):
            while mask&nums[r]:
                mask^=nums[l]
                l+=1
            mask^=nums[r]
            ans = max(ans,r-l+1)
        return ans