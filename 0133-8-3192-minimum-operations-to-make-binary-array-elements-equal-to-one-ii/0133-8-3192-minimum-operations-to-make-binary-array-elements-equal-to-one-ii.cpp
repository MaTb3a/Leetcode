class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flips = 0;
        for(int i = 0 ; i < nums.size();i++)
            flips+=(!((flips&1) ^ nums[i]));
        return flips;
        
    }
};