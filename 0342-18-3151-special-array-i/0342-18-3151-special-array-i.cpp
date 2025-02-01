class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        return ranges::adjacent_find(nums,[&](int a,int b){return (a&1) == (b&1);}) == nums.end();
    }
};