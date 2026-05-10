class Solution {
public:
    int dp[1001];
    int solve(int i,vector<int>& nums, int target,int n){
        if(i == n-1)
            return 0;
        int &ret = dp[i];
        if(~ret)return ret;
        ret = -1e9;
        for(int j = i+1; j < n;j++){
            if(nums[j] - nums[i] >= -target && nums[j] - nums[i] <= target)
                ret=max(ret,solve(j,nums,target,n)+1);
        }
        return ret;
        
    }
    int maximumJumps(vector<int>& nums, int target) {
        memset(dp,-1,sizeof dp);
        int ans  = solve(0,nums,target,nums.size());
        return ans <= 0 ? -1 : ans;
    }
};