class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int r = 0,len = 1;
        for(int l = 0 ; l < nums.size();l++){
            if(nums[l] != mx)continue;
            r = max(r,l);
            while(r < nums.size() && nums[r]  == mx){
                r++;
                len=max(len,r-l);
            }
        }
        return len;
    }
};