class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n = len(nums)
        ans = [1] * n
        
        # Step 1: Left pass
        left = 1
        for i in range(n):
            ans[i] = left
            left *= nums[i]

        # Step 2: Right pass
        right = 1
        for i in range(n - 1, -1, -1):
            ans[i] *= right
            right *= nums[i]

        return ans
