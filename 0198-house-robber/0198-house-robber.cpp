class Solution {
public:
    int dp[101];
    int solve(int idx,vector<int>& nums){
        if(idx>=nums.size())return 0;
        int &ret = dp[idx];
        if(~ret)return ret;
        ret = 0;
        ret=max(ret,solve(idx+2,nums)+nums[idx]);
        ret=max(ret,solve(idx+1,nums));
        return ret;
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return solve(0,nums);
    }
};