class Solution {
public:
    
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int l = 0 ,r = 0 , ans = 0, cur = 0;
        unordered_map<int,int>mp;
        while(r < nums.size()){
            mp[nums[r]]++;
            if(mp[nums[r]]==1)k--;
            r++;
            
            if( k < 0){
                k++;
                cur = 0;
                mp[nums[l++]]--;
             
            }
            if(!k){
                while(mp[nums[l]]>1){
                    cur++;
                    mp[nums[l++]]--;
                }
                ans+=cur+1;
            }
        }
        return ans;
    }
};