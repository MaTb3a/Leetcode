class Solution {
public:
    int dp[101][101];
    int solve(int idx,int op,string &s){
        if(idx == s.size())return !op;
        if(op<0)return 0;
        int &ret = dp[idx][op];
        if(~ret)return ret;
        ret =0;
        if(s[idx]=='('){
            ret=max(ret,solve(idx+1,op+1,s));
        }
        else if(s[idx]==')'){
            ret=max(ret,solve(idx+1,op-1,s));
        }
        else {
            ret=max(ret,solve(idx+1,op+1,s));
            ret=max(ret,solve(idx+1,op-1,s));
            ret=max(ret,solve(idx+1,op,s));
        }
        return ret;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,s);
    }
};