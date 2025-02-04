class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1; i < nums.size();i++){
            (nums[i] > nums[i-1]) ? nums[0]+=nums[i] :  nums[0] = nums[i];
            ans=max(ans,nums[0]);
        }
        return ans;
    }
};