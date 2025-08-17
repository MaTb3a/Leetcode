class Solution {
public:
  
    double new21Game(int n, int k, int maxPts) {
        vector<double>dp(n+1);

        dp[0]=1;
        double seg = k > 0 ? 1 : 0;
        for(int i=1 ; i <= n; i++){
            dp[i] = seg/maxPts;
            if(i < k)seg+=dp[i];
            if(i-maxPts >=0 && i - maxPts < k)
                seg-=dp[i-maxPts];
        }
        return accumulate(dp.begin() + k, dp.end(), 0.0);
    }
};