class Solution:
    def findTargetSumWays(self, nums, target):
        dp = [[0] * 3001 for _ in range(2)]
        dp[len(nums) % 2][1000] = 1  # Initialize the base case
        
        for i in range(len(nums) - 1, -1, -1):
            for j in range(3001):
                dp[i % 2][j] = (
                    (dp[(i + 1) % 2][j + nums[i]] if j + nums[i] <= 3000 else 0)
                    + (dp[(i + 1) % 2][j - nums[i]] if j - nums[i] >= 0 else 0)
                )
        
        return dp[0][target + 1000]
