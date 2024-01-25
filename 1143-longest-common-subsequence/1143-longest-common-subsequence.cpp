class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &a,string &b){
        if(i==a.size())return 0;
        if(j==b.size())return 0;
        int &ret=dp[i][j];
        if(~ret)return ret;
        ret = 0;
        if(a[i]==b[j])ret=max(ret,solve(i+1,j+1,a,b)+1);
        ret=max(ret,solve(i+1,j,a,b));
        ret=max(ret,solve(i,j+1,a,b));
        return ret;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,text1,text2);
    }
};