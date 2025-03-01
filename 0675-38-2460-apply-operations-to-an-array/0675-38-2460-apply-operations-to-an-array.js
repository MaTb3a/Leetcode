function applyOperations(nums) {
    let j = 0;
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        if (i + 1 < n && nums[i] === nums[i + 1] && nums[i] !== 0) {
            const x = nums[i];
            nums[i] = 0;
            nums[i + 1] = 0;
            nums[j++] = x * 2;
        } else if (nums[i] !== 0) {
            [nums[i], nums[j]] = [nums[j], nums[i]];
            j++;
        }
    }
    return nums;
}