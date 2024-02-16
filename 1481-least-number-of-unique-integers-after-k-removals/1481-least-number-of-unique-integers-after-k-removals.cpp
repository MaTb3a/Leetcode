class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto t : arr)mp[t]++;
        vector<pair<int,int>>v;
        for(auto t : mp)v.push_back({t.second,t.first});
        sort(v.begin(),v.end());
        int cnt = 0;
        for(auto t : v){
            if(k>=t.first)k-=t.first;
            else cnt++;
        }
        return cnt;
    }
};