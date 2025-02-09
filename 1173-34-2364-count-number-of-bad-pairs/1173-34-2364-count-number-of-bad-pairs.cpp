class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long bads = n * (n-1LL)/2;
        unordered_map<int,int>mp;
        for(int i = 0 ; i < n;i++)
            bads-=mp[nums[i]-i]++;
        return bads;
    }
};