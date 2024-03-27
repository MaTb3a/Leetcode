class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
       int n = nums.size() ,cnt = 0;
       long long cur = 1;
        for(int l = 0 , r = 0 ; r < n ; r++){
            cur*=nums[r];
            while(cur >= k)cur/=nums[l++];
            cnt+=r-l+1;
        }
        return cnt;
    }
};