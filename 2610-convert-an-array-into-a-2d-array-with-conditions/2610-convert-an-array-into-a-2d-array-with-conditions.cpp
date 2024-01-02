class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto t : nums)mp[t]++;
        vector<vector<int>>v;
        while(mp.size()){
            vector<int>tmp;
            for(auto &t : mp){
                if(t.second>0){
                    tmp.push_back(t.first);
                    t.second--;
                }
            }
            for(auto t : tmp)if(!mp[t])mp.erase(t);
            v.push_back(tmp);
        }
        
        return v;
    }
};