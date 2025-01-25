var lexicographicallySmallestArray = function(nums, limit) {
    const n = nums.length;
    const v = nums.map((val, i) => [val, i]).sort((a, b) => a[0] - b[0]);

    let i = 0;
    while (i < n) {
        const idx = [v[i][1]];
        let j = i + 1;
        while (j < n && v[j][0] - v[j - 1][0] <= limit) {
            idx.push(v[j][1]);
            j++;
        }
        idx.sort((a, b) => a - b);
        for (let k = 0; k < idx.length; k++) {
            nums[idx[k]] = v[i + k][0];
        }
        i = j;
    }

    return nums;
};
