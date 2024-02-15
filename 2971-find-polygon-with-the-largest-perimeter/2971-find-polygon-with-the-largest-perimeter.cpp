class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        int n = nums.size();
        for(int i = n-1 ; i >= 0 ;i--)
        {
            if(sum-nums[i] > nums[i])return sum;
            sum-=nums[i];
        }
        return -1;
        
    }
};