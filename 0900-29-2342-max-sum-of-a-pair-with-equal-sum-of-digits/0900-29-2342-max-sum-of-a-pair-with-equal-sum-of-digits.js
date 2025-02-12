var maximumSum = function(nums) {
    let ans = -1;
    let mp = new Map();

    for (let x of nums) {
        let sumDigits = [...String(x)].reduce((a, b) => a + Number(b), 0);
        if (mp.has(sumDigits)) {
            ans = Math.max(ans, mp.get(sumDigits) + x);
            mp.set(sumDigits, Math.max(mp.get(sumDigits), x));
        } else {
            mp.set(sumDigits, x);
        }
    }
    
    return ans;
};
