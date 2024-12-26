var findTargetSumWays = function(nums, target) {
    const dp = Array.from({ length: 2 }, () => Array(3001).fill(0));
    dp[nums.length % 2][1000] = 1; // Initialize base case
    
    for (let i = nums.length - 1; i >= 0; i--) {
        for (let j = 0; j < 3001; j++) {
            dp[i % 2][j] = 
                ((j + nums[i] <= 3000 ? dp[(i + 1) % 2][j + nums[i]] : 0)
                + (j - nums[i] >= 0 ? dp[(i + 1) % 2][j - nums[i]] : 0));
        }
    }
    
    return dp[0][target + 1000];
};
