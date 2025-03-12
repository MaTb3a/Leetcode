class Solution {
public:
    int maximumCount(vector<int>& nums) {
        return max((int)nums.size() - (upper_bound(nums.begin(),nums.end(),0) - nums.begin()) , lower_bound(nums.begin(),nums.end(),0) - nums.begin());
    }
};