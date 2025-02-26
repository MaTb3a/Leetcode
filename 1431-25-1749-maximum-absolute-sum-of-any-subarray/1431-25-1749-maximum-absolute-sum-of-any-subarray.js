/**
 * @param {number[]} nums
 * @return {number}
 */
var maxAbsoluteSum = function(nums) {
    let sum = 0,mn = 0,mx = 0
    for(let i = 0 ; i < nums.length;i++){
        sum+=nums[i];
        mx=Math.max(sum,mx);
        mn=Math.min(sum,mn);
    }
    return mx-mn;
};