class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(nums.begin(),nums.end(),0LL), l = 0;
        int n = nums.size(), cnt = 0;
        for(int i = 0 ; i < n -1;i++){
            l+=nums[i];
            cnt+=l >= (sum - l);
        }
        return cnt;
    }
};