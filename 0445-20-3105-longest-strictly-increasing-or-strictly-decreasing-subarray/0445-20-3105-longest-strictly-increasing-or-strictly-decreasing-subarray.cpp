class Solution {
public: // O(n*n) | O(1)
        // O(n) | O(n)
        // O(n) | O(1)
    
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = 1,len = 1,len2 = 1;
        for(int i = 1 ; i < nums.size();i++){
            (nums[i] > nums[i-1]) ? len++ : len = 1;
            (nums[nums.size()-i] < nums[nums.size()-i-1]) ? len2++ :  len2 = 1;
            mx=max({mx,len,len2});
        }
        return mx;
    }
};