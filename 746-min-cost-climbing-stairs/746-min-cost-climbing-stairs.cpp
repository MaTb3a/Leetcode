class Solution {
public:
    int dp[1001];
    int n;
    int solve(int i,vector<int>& cost){
        if(i>=n)
            return 0;
        int &ret=dp[i];
        if(~ret)return ret;
        ret=1e9;
        ret=min(ret,solve(i+1,cost)+cost[i]);
        ret=min(ret,solve(i+2,cost)+cost[i]);
        return ret;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        memset(dp,-1,sizeof dp);
        return min(solve(0,cost),solve(1,cost));
    }
    
};