class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>v = arr;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        for(auto it : arr)
            if(mp.find(it) == mp.end())
                mp[it] = mp.size()+1;
        
        for(auto &it : v)it = mp[it];
        return v;
    }
};