class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        vis = {}
        ans = -1
        for i in nums:
            if i > 0 and -i in vis:
                ans=max(ans,i)
            if i < 0 and -i in vis:
                ans=max(ans,-i)
            vis [i] = 1
        return ans
