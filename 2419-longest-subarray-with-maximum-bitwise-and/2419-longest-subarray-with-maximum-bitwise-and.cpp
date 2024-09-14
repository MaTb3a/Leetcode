class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int ans = 0, curLength = 0;
        for(int it : nums){
            if(it == mx)curLength++;
            else ans=max(ans,curLength),curLength=0;
        }
        return max(curLength,ans);
    }
};