class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<unordered_map<long long,int>>dp(n);
        for(int i = 1 ; i < n;i++){
            for(int j = 0 ; j < i ;j++){
                long long diff = (long long)nums[i] - nums[j];
                dp[i][diff] += (1+dp[j][diff]);
                ans+=dp[j][diff];
            }
        }
        return ans;
    }
};