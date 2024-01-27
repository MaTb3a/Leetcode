class Solution {
public:
    int dp[1001][1001];
    int mod = 1e9+7;
    int solve(int i ,int rem){
        if(!i)return 0;
        if(!rem)return 1;
        int &ret=dp[i][rem];
        if(~ret)return ret;
        ret = 0;
        for(int j = 0; j <= min(i-1,rem);j++){
            ret=(ret+solve(i-1,rem-j)%mod)%mod;
        }
        return ret;
    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof dp);
        return solve(n,k);
    }
};