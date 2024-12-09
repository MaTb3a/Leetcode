var isArraySpecial = function(nums, queries) {
    const n = nums.length;

    for (let i = 1; i < n; i++) {
        if ((nums[i] & 1) === (nums[i - 1] & 1)) {
            nums[i - 1] = 1;
        } else {
            nums[i - 1] = 0;
        }
    }

    // Compute prefix sums
    for (let i = 1; i < n; i++) {
        nums[i] += nums[i - 1];
    }

    // Process queries
    return queries.map(([l, r]) => {
        if (l === r) {
            return true;
        }
        const res = (r > 0 ? nums[r - 1] : nums[r]) - (l > 0 ? nums[l - 1] : 0);
        return res === 0;
    });
};
