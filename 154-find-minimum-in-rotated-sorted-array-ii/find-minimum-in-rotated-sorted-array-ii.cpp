class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        int last = nums[n];
        int left = 0, right = n;

        while (left < n && nums[left] == last)
            left++;

        while (left < right) {
            int mid = left + right >> 1;

            if (nums[mid] > last)
                left = mid + 1;
            else
                right = mid;
        }

        return nums[left];
    }
};