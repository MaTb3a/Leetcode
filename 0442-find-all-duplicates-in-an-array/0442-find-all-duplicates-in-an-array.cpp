class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>v;
        for(int i = 0 ; i < nums.size();i++){
           int x = abs(nums[i]);
            if(nums[x-1]<0)v.push_back(x);
            nums[x-1]*=-1;
        }
        return v;
    }
};