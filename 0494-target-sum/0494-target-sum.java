class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int[][] dp = new int[2][3001];
        dp[nums.length % 2][1000] = 1;
        
        for (int i = nums.length - 1; i >= 0; i--) {
            for (int j = 0; j < 3001; j++) {
                dp[i % 2][j] = 
                    ((j + nums[i] <= 3000 ? dp[(i + 1) % 2][j + nums[i]] : 0)
                    + (j - nums[i] >= 0 ? dp[(i + 1) % 2][j - nums[i]] : 0));
            }
        }
        
        return dp[0][target + 1000];
    }
}
