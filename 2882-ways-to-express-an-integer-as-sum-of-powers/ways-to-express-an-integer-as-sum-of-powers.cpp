class Solution {
public:
    const int mod = 1e9+7;
    int dp[302][302];
    long long po[302];
    int solve(int n,long long cur,int st){
        if(cur > n || st > 301)return 0;
        if(cur == n)return 1;
        int &ret= dp[cur][st];
        if(~ret)return ret;
        ret = 0;
        ret = (ret + solve(n,cur+po[st],st+1))%mod;
        ret = (ret + solve(n,cur,st+1))%mod;

        return ret;
    }
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof dp);
        for(int i = 1 ; i <= 301;i++)
            po[i] = pow(i,x);
        return solve(n,0,1);
    }
};