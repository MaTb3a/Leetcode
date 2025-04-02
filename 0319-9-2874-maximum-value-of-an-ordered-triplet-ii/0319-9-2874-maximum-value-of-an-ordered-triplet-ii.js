/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumTripletValue = function(nums) {
    let ans = 0;
    let mx = nums[0];
    let d = 0;
    
    for (let i = 2; i < nums.length; i++) {
        d = Math.max(d, mx - nums[i-1]);
        ans = Math.max(ans, d * nums[i]);
        mx = Math.max(mx, nums[i-1]);
    }
    
    return ans;
};