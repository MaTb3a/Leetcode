class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        lst = -1
        ans = 0
        mn_idx,mx_idx = -1,-1
        for i in range(0,len(nums)):
            if nums[i] < minK or nums[i] > maxK:
                mn_idx=mx_idx = -1
                lst = i
            else:
                if nums[i] == minK:
                    mn_idx = i
                if nums[i] == maxK:
                    mx_idx = i
                if mn_idx != -1 and mx_idx != -1:
                    ans+=min(mn_idx,mx_idx)-lst
        return ans