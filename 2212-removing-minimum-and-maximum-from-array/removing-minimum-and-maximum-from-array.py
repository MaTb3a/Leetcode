class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        minidx = nums.index(min(nums))
        maxidx = nums.index(max(nums))
        l = min(minidx, maxidx)  
        r = max(minidx, maxidx)
        n = len(nums)
        return min(
            r + 1, n - l, l + 1 + n - r
        )  