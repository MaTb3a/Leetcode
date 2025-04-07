class Solution {
public:


    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;
        int k = sum / 2;
        bitset<10001>dp(1);
        for(int x : nums)
            for(int r = k ; r - x >=0; r--)
                    dp[r] = dp[r] | dp[r - x];  
        return dp[k];
    }
};