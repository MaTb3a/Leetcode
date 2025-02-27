class Solution {
public:
    int dp[1001][1001];
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(),ans = 0;
        unordered_map<int,int>mp;
        for(int i = 0 ; i < n;i++)mp[arr[i]] = i; 

        for(int i = 0 ; i < n ;i++)
            for(int j = i+1 ; j < n;j++){
               
                if(mp.count(arr[i]+arr[j])){
                    int nxt = mp[arr[i]+arr[j]];
                    dp[j][nxt] = dp[i][j]+1;
                    ans = max(ans,dp[j][nxt]);
                }
              
            }
        return ans ? ans + 2 : 0;
            // 2 >
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();