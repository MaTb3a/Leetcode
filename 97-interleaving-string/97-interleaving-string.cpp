class Solution {
public:
    int dp[101][101][201];
    bool solve(int i,int j,int k,string &s1, string &s2, string &s3){
        if(i+j==s3.size())
            return 1;
        int &ret=dp[i][j][k];
        if(~ret)return ret;
        ret=0;
        if(s1[i]==s3[k])
            ret|=solve(i+1,j,k+1,s1,s2,s3);
        if(s2[j]==s3[k])
            ret|=solve(i,j+1,k+1,s1,s2,s3);
        return ret;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof dp);
        return s1.size()+s2.size()== s3.size() ? solve(0,0,0,s1,s2,s3) : 0;
    }
};