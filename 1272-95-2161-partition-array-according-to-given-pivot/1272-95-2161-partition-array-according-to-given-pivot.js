/**
 * @param {number[]} nums
 * @param {number} pivot
 * @return {number[]}
 */
var pivotArray = function(nums, pivot) {
    const ans = new Array(nums.length).fill(0);
        let less_i = 0;
        let greater_i = nums.length - 1;
        
        for (let i = 0; i < nums.length; i++) {
            if (nums[i] < pivot) {
                ans[less_i] = nums[i];
                less_i++;
            }
        }
    
        let greater_start = nums.length - 1;
        
        for (let j = nums.length - 1; j >= 0; j--) {
            if (nums[j] > pivot) {
                ans[greater_start] = nums[j];
                greater_start--;
            }
        }
        
        while (less_i <= greater_start) {
            ans[less_i] = pivot;
            less_i++;
        }
        
        return ans;
};
