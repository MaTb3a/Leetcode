class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        s,mn,mx = 0,0,0
        for x in nums:
            s+=x
            mn=min(mn,s)
            mx=max(mx,s)
        return mx-mn