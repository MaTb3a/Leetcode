class Solution {
public:
    int n;
    int dp[105];
    int solve(int idx,string &s){
          if(s[idx]=='0')
            return 0;
        if(idx>=n-1)
            return 1;
      
   
        int &ret=dp[idx];
        if(~ret)return ret;
        
        int x = stoi(s.substr(idx,2));
        if(x>=1&&x<=26)
            ret=(solve(idx+1,s)+solve(idx+2,s));
        else
            ret=solve(idx+1,s);
        return ret;       
    }
    int numDecodings(string s) {
        n=s.size();
        memset(dp,-1,sizeof dp);
        return solve(0,s);
    }
};