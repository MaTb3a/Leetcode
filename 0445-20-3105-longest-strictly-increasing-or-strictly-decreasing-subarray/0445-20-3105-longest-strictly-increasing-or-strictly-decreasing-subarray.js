var longestMonotonicSubarray = function(nums) {
    let maxLen = 1, inc = 1, dec = 1;
    let n = nums.length;

    for (let i = 1; i < n; i++) {
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

        maxLen = Math.max(maxLen, inc, dec);
    }
    return maxLen;
};
