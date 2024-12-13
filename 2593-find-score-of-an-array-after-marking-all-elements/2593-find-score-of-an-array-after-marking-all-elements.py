class Solution:
    def findScore(self, nums: list[int]) -> int:
        n = len(nums)
        total_sum = 0
        r = 0
        
        while r < n:
            l = r
            while r + 1 < n and nums[r + 1] < nums[r]:
                r += 1
            for i in range(r, l - 1, -2):
                total_sum += nums[i]
            r += 2 
        
        return total_sum
