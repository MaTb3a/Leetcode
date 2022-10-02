class Solution {
public:
    int kk,nn;
    const int mod = 1e9+7;
    int dp[31][300001];
    int solve(int idx,int rem){
        if(rem<0)
            return 0;
        if(idx==nn)
            return !rem;
        int &ret=dp[idx][rem];
        if(~ret)return ret;
        ret=0;
        for(int i=1;i<=kk;i++)
            ret=(ret+solve(idx+1,rem-i))%mod;
        return ret%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        nn=n;kk=k;
        memset(dp,-1,sizeof dp);
        return solve(0,target);
    }
};