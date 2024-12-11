var maximumBeauty = function(nums, k) {
    const mx = Math.max(...nums);

    const vis = new Array(mx + 2).fill(0);

    for (const x of nums) {
        vis[Math.max(0, x - k)]++;
        vis[Math.min(x + k + 1, mx + 1)]--;
    }

    let ans = 0, cnt = 0;
    for (const x of vis) {
        cnt += x;
        ans = Math.max(ans, cnt);
    }

    return ans;
};
