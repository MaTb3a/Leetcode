class Solution {
public:
    int dp[55][55][55];
    const int mod = 1e9+7;
    int solve(int i,int j,int step,int n,int m){
        
        if(i < 0 || j < 0 || i >=n || j >=m)return 1;
        if(!step)return 0;
        int &ret = dp[i][j][step];
        if(~ret)return ret;
        ret = 0;
        ret= (0LL+ret+solve(i+1,j,step-1,n,m))%mod;
        ret= (0LL+ret+solve(i-1,j,step-1,n,m))%mod;
        ret= (0LL+ret+solve(i,j+1,step-1,n,m))%mod;
        ret= (0LL+ret+solve(i,j-1,step-1,n,m))%mod;

        return ret%mod;

    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof dp);
        return solve(startRow,startColumn,maxMove,m,n);
    }
};