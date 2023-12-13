class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1 = 0, mx2 =0;
        mx1 = *max_element(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size();i++)if(nums[i]==mx1){nums[i]=0;break;}
        mx2 = *max_element(nums.begin(),nums.end());
        return ((mx1-1)*(mx2-1));
    }
};