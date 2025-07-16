class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int dp[4] ={0};
        for(int x : nums){
            if(x&1){
                dp[0] = max(dp[0],dp[1]+1);
                dp[3]++;
            }
            else {
                dp[1] = max(dp[1],dp[0]+1);
                dp[2]++;
            }
        }
        return *max_element(dp,dp+4);
    
    }
};