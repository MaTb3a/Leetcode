class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        cnt2 = 0
        for num in nums:
            if not cnt2:
                x = num
            cnt2 += (num == x)
            cnt2 -= (num != x)
        
        cnt2 = nums.count(x)
        n = len(nums)
        cnt1 = 0
        
        for i in range(n):
            cnt1 += (nums[i] == x)
            cnt2 -= (nums[i] == x)
            if cnt1 * 2 > i + 1 and cnt2 * 2 > n - (i + 1):
                return i
        
        return -1