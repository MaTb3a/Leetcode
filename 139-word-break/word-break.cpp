
class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string> st(wordDict.begin(),wordDict.end());
         vector<int>dp(303);
         dp[0] = 1;
         int n = s.size();
         for(int i = 0 ; i < n;i++){
            for(int len = 1; len <= n; len++){
                if(dp[i] && i+len <= n && st.count(s.substr(i,len)))
                    dp[i+len] = true;
            }
         }
         return dp[n];

    }
};