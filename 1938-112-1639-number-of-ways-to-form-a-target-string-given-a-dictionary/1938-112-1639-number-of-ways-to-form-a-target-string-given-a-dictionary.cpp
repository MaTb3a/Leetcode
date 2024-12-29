class Solution {
public:
    int dp[2][1002];
    const int mod = 1e9+7;
    int solve(int i,int k,vector<vector<int>>&frq,string &s,int &n,int &m){
        if(i == n)return 1;
        if(k == m)return 0;
        int &ret = dp[i][k];
        if(~ret)return ret;
        ret = solve(i,k+1,frq,s,n,m);
        if(frq[k][s[i]-'a'])
            ret=(ret +1LL*solve(i+1,k+1,frq,s,n,m)*frq[k][s[i]-'a'])%mod;
        return ret;
    }
    int numWays(vector<string>& words, string target) {
        int n = target.size(),m = words[0].size();
        vector<vector<int>>frq(m,vector<int>(26));
        for(int k = 0 ; k < m ;k++)
            for(string w : words)frq[k][w[k]-'a']++;

        for(int k = 0 ; k <= m ;k++)dp[n&1][k] = 1;
        
        for(int i = n-1 ; i >= 0 ; i--){
            for(int k = m-1 ; k >= 0; k--){
                 dp[i&1][k] = dp[i&1][k+1];
                   if(frq[k][target[i]-'a'])
                        dp[i&1][k]=(dp[i&1][k] +1LL*dp[(i+1)&1][k+1]*frq[k][target[i]-'a'])%mod;
            }
            memset(dp[(i+1)&1],0,sizeof dp[(i+1)&1]);
        }
        return dp[0][0];
    }
};