class Solution {
public:
    int dp[13][10005];
    int solve(int i,int amount,vector<int>& coins){
        if(amount == 0)return 0;
        if(amount < 0 || i == coins.size())return 1e9;
        int &ret= dp[i][amount];
        if(~ret)return ret;
        ret = solve(i+1,amount,coins);
        ret=min(ret,solve(i+1,amount-coins[i],coins)+1);
        ret=min(ret,solve(i,amount-coins[i],coins)+1);
        return ret;

    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof dp);
        int ans = solve(0,amount,coins);
        return ans == 1e9 ? -1 : ans;
    }
};