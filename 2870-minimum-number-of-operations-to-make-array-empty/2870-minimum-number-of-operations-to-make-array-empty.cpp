class Solution {
public:
    int minOperations(vector<int>& nums) {
     
        
        unordered_map<int,int>mp;
        for(auto t: nums)mp[t]++;
        int cnt=0;
        for(auto t : mp){
            if(t.second==1)return -1;
            cnt+=ceil(t.second/3.0);
        }
        return cnt;
    }
};