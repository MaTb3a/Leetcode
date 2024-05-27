class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        if nums[-1] > len(nums):
            return len(nums)
        
        if nums[0] == 0:
            return -1
        
        l = 0
        r = len(nums) - 1
        m = 0
        
        while l <= r:
            m = l + (r - l) // 2
            if nums[m] > m:
                l = m + 1
            elif nums[m] < m:
                r = m - 1
            else:
                return -1
        
        return m + 1 if nums[m] > m else m
