class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 1,2,3,4,5,6,7
        # 5,6,7,1,2,3,4
        n = len(nums)
        k%=n
        nums[:] = nums[n-k:] + nums[:n-k]