class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int y : nums)x^=y;
        return x;
    }
};