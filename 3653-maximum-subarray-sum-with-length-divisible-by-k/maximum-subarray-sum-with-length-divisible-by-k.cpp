class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>prefix(n+1);
        
        for(int i = 1; i<= n;i++)
            prefix[i] = prefix[i-1] + nums[i-1];
        
        long long ans = -1e18;
        map<int,long long>mp;
        for(int i = 1; i<= k-1;i++)
            mp[i] = prefix[i];
        
        for(int i = k ; i <=n ;i++){
            ans=max(ans,prefix[i] - mp[i%k]);
            mp[i%k] = min(mp[i%k],prefix[i]);
        }
        return ans;
    }
};