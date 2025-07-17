class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size(),ans = 0;
        vector<vector<int>>dp(k,vector<int>(k));
        for(int i = 0 ; i < n;i++){
            int cur = nums[i]%k;
            for(int j = 0 ; j < k;j++){
                dp[j][cur] = dp[cur][j] +1;
                ans=max(ans,dp[j][cur]);
            }
        }
        return ans;
    }
};