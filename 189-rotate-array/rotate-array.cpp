class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin() + k%nums.size());
        reverse(nums.begin()+ k%nums.size() ,nums.end());
    }
};