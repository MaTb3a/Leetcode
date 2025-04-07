class Solution:
    def canPartition(self, nums: List[int]) -> bool:
     
        s = sum(nums)
        if s &1:
            return False
        target = s //2
        dp = [False]*(target+1)
        dp[0] = True
        for num in nums:
            for r in range(target,num-1,-1):
                dp[r] = dp[r] or dp[r-num]
        return dp[target]