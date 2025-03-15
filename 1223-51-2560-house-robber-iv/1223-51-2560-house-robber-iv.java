class Solution {
    public int minCapability(int[] nums, int k) {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        
        for (int num : nums) {
            min = Math.min(min, num);
            max = Math.max(max, num);
        }
        
        int result = -1;
        int left = min;
        int right = max;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canRob(nums, mid, k)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
    
    private boolean canRob(int[] nums, int capability, int k) {
        int count = 0;
        int i = 0;
        
        while (i < nums.length) {
            if (nums[i] <= capability) {
                count++;
                i += 2; 
            } else {
                i += 1; 
            }
        }
        
        return count >= k;
    }
}