class Solution {
public:
    long long dp[100001];
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        for(int i = n-1;  i >=0 ;i--){
            int nxt = min(n,i+1+questions[i][1]);
            dp[i] = max( dp[i+1] , dp[nxt] + questions[i][0]);
        }
        return dp[0];
    }
};