class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre = nums;
        for(int i = 1 ; i < n;i++)pre[i]+=pre[i-1];
        vector<int>v(n);
        v[0] = abs(nums[0]*n-pre[n-1]);
        v[n-1] = abs(nums[n-1]*n -pre[n-1]);
        for(int i = 1; i < n-1;i++){
            v[i] = abs(i*nums[i] - pre[i-1]) + abs((n-i-1)*nums[i] - (pre[n-1]-pre[i]));
        }
        return v;
    }
};