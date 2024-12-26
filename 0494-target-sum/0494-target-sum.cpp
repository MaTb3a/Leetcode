class Solution {
public:
    int dp[2][3001];
  
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        dp[n&1][1000] = 1;
        for(int i = n-1 ; i >=0 ;i--){
            for(int j = 0 ; j < 3001 ;j++)
                dp[i&1][j] = (j+nums[i] > 3000 ? 0 : dp[(i+1)&1][j+nums[i]]) + (j-nums[i]  < 0 ? 0 : dp[(i+1)&1][j-nums[i]]);
        }
        return dp[0][target+1000];
    }
};