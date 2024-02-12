class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto t : nums)mp[t]++;
        for(auto t : mp)if(t.second > n/2)return t.first;
        return -1;
    }
};