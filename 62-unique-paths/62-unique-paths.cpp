class Solution {
public:
    long long dp[101][101];
    long long solve(int i,int j){
        if(i==1 && j==1)return 1;
        if(i<= 0||j<=0)return 0;
        long long &ret=dp[i][j];
        if(~ret)return ret;
        ret=0;
        ret+=solve(i-1,j);
        ret+=solve(i,j-1);
        return ret;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof dp);
        return solve(m,n);
    }
};