class Solution:
    def dailyTemperatures(self, nums: List[int]) -> List[int]:
        stk = []
        ans = [0]*len(nums)
        for i in range(len(nums)-1,-1,-1):
            while stk and nums[i] >= nums[stk[-1]]:
                stk.pop()
            if stk:
                ans[i] = stk[-1] -i            
            stk.append(i)
        
        return ans

