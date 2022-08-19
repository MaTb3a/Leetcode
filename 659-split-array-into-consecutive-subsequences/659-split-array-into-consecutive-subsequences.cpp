class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>mp;
        unordered_map<int,int>seq;
        for(auto t : nums)mp[t]++;
        for(auto t: nums){
            if(!mp[t])
                continue;
            mp[t]--;
            if(seq[t-1]){
                seq[t-1]--;
                seq[t]++;
            }
            else if(mp[t+1] && mp[t+2]){
                mp[t+1]--;mp[t+2]--;
                seq[t+2]++;
            }
            else return 0;
            
        }
        return 1;
        
    }
};