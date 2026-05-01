class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long totalSum = 0;
        long long cur = 0;

        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
            cur += 1LL * i * nums[i]; // F(0)
        }

        long long ans = cur;

        for (int k = 1; k < n; k++) {
            cur = cur + totalSum - 1LL * n * nums[n - k];
            ans = max(ans, cur);
        }

        return ans;
    }
};