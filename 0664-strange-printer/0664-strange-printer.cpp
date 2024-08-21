class Solution {
public:
    int dp[101][101];
    int solve(int l,int r,string &s){
        if(l>r) return 0;
        int &ret = dp[l][r];
        if(~ret)return ret;
        ret = solve(l+1,r,s)+1;
        char curChar = s[l];
        for(int k = l+1;k<=r;k++){
            if(s[k]==curChar)
              ret=min(ret,solve(l,k-1,s) + solve(k+1,r,s));
        }
        return ret;
    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof dp);
        return solve(0,s.size()-1,s);
    }
};