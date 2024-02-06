class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto t : strs){
            string tmp = t;
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(t);
        }
        for(auto t : mp)ans.push_back(t.second);
        return ans;
    }
};