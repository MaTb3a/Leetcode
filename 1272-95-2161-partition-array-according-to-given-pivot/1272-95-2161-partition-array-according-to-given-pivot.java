class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int[] ans = new int[nums.length];
        int less_i = 0;
        int greater_i = nums.length - 1;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < pivot) {
                ans[less_i] = nums[i];
                less_i++;
            }
        }

        for (int j = nums.length - 1; j >= 0; j--) {
            if (nums[j] > pivot) {
                ans[greater_i] = nums[j];
                greater_i--;
            }
        }

        while (less_i <= greater_i) {
            ans[less_i] = pivot;
            less_i++;
        }

        return ans;
    }
}