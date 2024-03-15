class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>l = nums,r = nums ,ans(nums.size());
        for(int i = 1 ; i < n;i++)l[i]*=l[i-1];
        for(int i = n-2 ; ~i ;i--)r[i]*=r[i+1];
        for(int i=0;i<n;i++)
            ans [i] = (i-1 <0 ? 1 : l[i-1])  * (i+1== n ? 1 : r[i+1]);
        return ans;
    }
};