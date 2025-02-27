/**
 * @param {number[]} arr
 * @return {number}
 */
var lenLongestFibSubseq = function(arr) {
    const n = arr.length;
    const dp = Array.from({ length: n }, () => Array(n).fill(0)); 
    const mp = new Map(); 
    let ans = 0;

    for (let i = 0; i < n; i++) {
        mp.set(arr[i], i);
    }

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const nextVal = arr[i] + arr[j];
            if (mp.has(nextVal)) {
                const nextIdx = mp.get(nextVal);
                dp[j][nextIdx] = dp[i][j] + 1; 
                ans = Math.max(ans, dp[j][nextIdx]); 
            }
        }
    }

    return ans > 0 ? ans + 2 : 0;
};