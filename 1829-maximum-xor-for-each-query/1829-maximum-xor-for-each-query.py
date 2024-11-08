class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        xr = 0
        n = len(nums)
        for i in range(n):
            xr = xr^nums[i]
        
        mask = (1<<maximumBit)-1
        for i in range(n):
            k = mask ^ xr
            xr^=nums[n - i -1]
            nums[n-i-1] = k
        nums.reverse()
        return nums
