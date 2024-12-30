class Solution {
public:
    int dp[100001];
    const int mod = 1e9+7;
    
    int countGoodStrings(int low, int high, int zero, int one) {
        for(int i = low; i<= high;i++)dp[i]= 1;
        for(int i = high ; i >= 0 ;i--){
            if(i+zero < 100001) dp[i]+=(dp[i+zero]);
            if(i+one < 100001) dp[i]+=(dp[i+one]);
            dp[i]%=mod;
        }
        return dp[0];
    }
};