class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int r = accumulate(nums.begin(),nums.end(),0);
        int l = 0;
        for(int i = 0 ; i < nums.size();i++){
            r-=nums[i];
            int x = nums[i];
            nums[i] = abs(l-r);
            l+=x;
        }
        return nums;
    }
};