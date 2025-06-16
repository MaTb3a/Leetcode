class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        stk = [nums[0]]
        ans = -1
        for i in range(1,len(nums)):

            if stk and nums[i] > stk[-1]:
                ans=max(ans,nums[i] - stk[-1])

            while stk and stk[-1] > nums[i]:
                stk.pop()
            
            
            if not stk or nums[i] < stk[-1]:
                stk.append(nums[i])

        return ans