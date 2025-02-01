var isArraySpecial = function(nums) {
    return nums.every((num, i) => i === 0 || (nums[i - 1] % 2 !== num % 2));
};
