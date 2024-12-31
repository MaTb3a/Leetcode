class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lst = days.back();
        vector<int>dp(366);
       
        for(int d = 1,i = 0 ; d <= lst ;d++){
            if(d < days[i]){
                dp[d] = dp[d-1];
                continue;
            }
            int ch1 = costs[0] + dp[d-1];
            int ch2 = costs[1] + dp[max(0,d-7)];
            int ch3 = costs[2] + dp[max(0,d-30)];
            dp[d] = min({ch1,ch2,ch3});
            i++;
        }
        return dp[lst];
    }
};