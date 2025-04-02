class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0,d = 0, mx = nums[0];
        for(int k = 2 ; k < nums.size();k++){
            d= max(d, (mx - nums[k-1]) );
            ans = max(ans,d* nums[k]);
            mx=max(mx,1LL*nums[k-1]);
        }
        return ans;
    }
};