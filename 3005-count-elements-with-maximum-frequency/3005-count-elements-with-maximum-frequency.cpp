class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mx = 0;
        for(auto t : nums)mp[t]++,mx=max(mx,mp[t]);
        int ans = 0;
        for(auto t : mp)if(t.second == mx)ans+=mx;
        return ans;
    }
};