class Solution {
public:
    int dp[1001][1001];
   
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size(),m = b.size();
        for(int j = 0 ; j <=m ;j++) dp[n][j] = m - j;
        for(int i = 0 ; i <=n ;i++) dp[i][m] = n - i;

        for(int i = n-1;i >= 0 ; i--)
            for(int j = m -1 ; j >= 0 ; j--){
                if(a[i] == b[j])
                    dp[i][j] = dp[i+1][j+1]+1;
                else {
                    dp[i][j] = min(dp[i+1][j], dp[i][j+1])+1;
                }
            }
        
        string ans;
        int i = 0, j = 0;
        while(i < n && j < m){
            if(a[i] == b[j] && dp[i][j] == dp[i+1][j+1]+1)ans.push_back(a[i++]),j++;                
            else if(dp[i][j] ==  dp[i+1][j]+1) ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
        }
        ans+= b.substr(j);
        ans+= a.substr(i);

        return ans;
    }
};