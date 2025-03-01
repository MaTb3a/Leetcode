class Solution {
    public int[] applyOperations(int[] nums) {
        int j = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && nums[i] == nums[i + 1] && nums[i] != 0) {
                int x = nums[i];
                nums[i] = 0;
                nums[i + 1] = 0;
                nums[j++] = x * 2;
            } else if (nums[i] != 0) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
        }
        return nums;
    }
}