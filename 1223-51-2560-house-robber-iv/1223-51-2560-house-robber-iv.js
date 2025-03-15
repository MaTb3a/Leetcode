/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minCapability = function(nums, k) {
    // Find min and max values in nums
    let min = Math.min(...nums);
    let max = Math.max(...nums);
    
    let result = -1;
    let left = min;
    let right = max;
    
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        
        if (ok(nums, mid, k)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
};

function ok(nums, capability, k) {
    let count = 0;
    let i = 0;
    
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