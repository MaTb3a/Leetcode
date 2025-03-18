class Solution {
public:
   
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, ans = 0,mask = 0;
        for(int r = 0 ; r < nums.size();r++){
            while(mask & nums[r])mask^=nums[l++];
            mask^=nums[r];
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};