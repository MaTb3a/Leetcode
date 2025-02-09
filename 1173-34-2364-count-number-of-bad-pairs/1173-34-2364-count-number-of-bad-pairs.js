var countBadPairs = function(nums) {
    let n = nums.length;
    let bads = BigInt(n) * BigInt(n - 1) / 2n; 
    let mp = new Map();

    for (let i = 0; i < n; i++) {
        let key = nums[i] - i;
        let count = mp.get(key) || 0;
        bads -= BigInt(count); 
        mp.set(key, count + 1);
    }

    return Number(bads);
};
