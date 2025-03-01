class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int j = 0;
        for(int i = 0 ; i < nums.size();i++){
            if(i+1 < nums.size() && nums[i] == nums[i+1] && nums[i]){
                int x = nums[i];
                nums[i] = nums[i+1] = 0;
                nums[j++] = x*2;
            }
            else if(nums[i])
                swap(nums[i],nums[j++]);
        }
        return nums;
    }
};