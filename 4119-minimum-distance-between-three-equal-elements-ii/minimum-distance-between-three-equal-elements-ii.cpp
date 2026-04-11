class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;        
        for(int i = 0 ; i < nums.size();i++)
            mp[nums[i]].push_back(i);
        int ans = INT_MAX;
        for(auto it : mp){
            if(it.second.size()>=3)
                for(int i = 1 ; i < it.second.size()-1;i++){
                    ans=min(ans,it.second[i] - it.second[i-1] + it.second[i+1] - it.second[i] + it.second[i+1] - it.second[i-1]);
                }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};