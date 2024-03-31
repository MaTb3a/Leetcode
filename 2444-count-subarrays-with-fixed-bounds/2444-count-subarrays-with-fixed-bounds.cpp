class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int j = -1;
        int mnIdx = -1;
        int mxIdx = -1;

        for (int i = 0; i < nums.size(); ++i) {
          if (nums[i] < minK || nums[i] > maxK)
            j = i;
          if (nums[i] == minK)
            mnIdx = i;
          if (nums[i] == maxK)
            mxIdx = i;
          ans += max(0, min(mnIdx, mxIdx) - j);
        }

        return ans;

    }
};