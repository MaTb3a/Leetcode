class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       for(int i = 0 ; i < nums.size() ; i++){
           while(i+1 != nums[i] && (nums[i] <= nums.size() && nums[i] >= 1)){
               if(nums[i]==nums[nums[i]-1])break;
               swap(nums[i],nums[nums[i]-1]);
           }
       }
        for(int i = 0 ; i < nums.size();i++)
            if(i+1 != nums[i])return i+1;
        return nums.size()+1;
    }
};
