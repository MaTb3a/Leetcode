class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(auto t : nums1){
            if(mp.find(t)==mp.end())mp[t]=1;
        }
        for(auto t : nums2){
            if(mp[t]==1)mp[t]=2;
        }
        vector<int>v;
        for(auto t : mp)if(t.second ==2)v.push_back(t.first);
        return v;
    }
};