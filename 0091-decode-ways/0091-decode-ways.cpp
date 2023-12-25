class Solution {
public:
    int dp[103];
    int solve(int i,string &s){
        if(i==s.size())return 1;
        if(s[i]=='0')return 0;
        int &ret = dp[i];
        if(~ret)return ret;
        ret = 0;
        if(i+1<s.size() && (s[i]-'0')*10 + (s[i+1]-'0') <=26){
            ret+=solve(i+2,s);
            ret+=solve(i+1,s);
        }
        else ret+=solve(i+1,s);
        return ret;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof dp);
        return solve(0,s);
    }
};