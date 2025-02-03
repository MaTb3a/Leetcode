class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int maxLen = 1, inc = 1, dec = 1;
        int n = nums.length;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
            } else {
                inc = 1;
            }

            if (nums[i] < nums[i - 1]) {
                dec++;
            } else {
                dec = 1;
            }

            maxLen = Math.max(maxLen, Math.max(inc, dec));
        }
        return maxLen;
    }
}
