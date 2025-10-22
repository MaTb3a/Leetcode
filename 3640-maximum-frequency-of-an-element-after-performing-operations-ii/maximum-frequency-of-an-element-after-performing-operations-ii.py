class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        nums.sort()
        n, left, right, i, max_freq = len(nums), 0, 0, 0, 0
        
        while i < n:
            target = nums[i]
            count = 0
            while i < n and nums[i] == target:
                count += 1
                i += 1
            
            while left < n and nums[left] < target - k:
                left += 1
            
            while right < n and nums[right] <= target + k:
                right += 1
            max_freq = max(max_freq, min(right - left, count + numOperations))
        
        if max_freq >= numOperations: return max_freq
        
        left, max_freq_no_target = 0, 0
        for right, val in enumerate(nums):
            while nums[left] < val - 2 * k:
                left += 1
            max_freq_no_target = max(max_freq_no_target, right - left + 1)
        
        return max(max_freq, min(max_freq_no_target, numOperations))