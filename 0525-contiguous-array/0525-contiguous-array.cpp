class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       unordered_map<int,int>mp;
       int mx = 0,sum = 0;
       for(int i = 0 ; i < nums.size();i++){
            sum += nums[i] == 1 ? 1 : -1;
            if(!sum)mx = i+1;
            else if(mp.find(sum)==mp.end())mp[sum] = i;
            else mx = max(mx,i-mp[sum]);
       }
       return mx;
        
    }
};