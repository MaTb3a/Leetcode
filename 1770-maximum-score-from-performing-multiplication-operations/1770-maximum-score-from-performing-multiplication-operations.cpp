class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int solve(int l,int r,vector<int>& nums, vector<int>& multipliers){
        if(r==m)return 0;
        if (dp[l][r] != INT_MIN) return dp[l][r];
        int left=solve(l+1,r+1,nums,multipliers)+(nums[l]*multipliers[r]);
        int right=solve(l,r+1,nums,multipliers)+(nums[(n - 1) - (r - l)]*multipliers[r]);
        return dp[l][r]=max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n=nums.size();
        m=multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));

        return solve(0,0,nums,multipliers);
    }
};