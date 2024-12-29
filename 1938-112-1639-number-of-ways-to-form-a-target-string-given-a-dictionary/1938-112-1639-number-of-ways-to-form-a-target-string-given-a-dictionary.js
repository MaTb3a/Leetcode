var numWays = function(words, target) {
    const mod = 1e9 + 7;
    const n = target.length, m = words[0].length;
    
    // Frequency array for each column of words
    const frq = Array.from({ length: m }, () => Array(26).fill(0));
    for (const word of words) {
        for (let k = 0; k < m; k++) {
            frq[k][word.charCodeAt(k) - 'a'.charCodeAt(0)]++;
        }
    }

    // DP table
    let dp = Array(2).fill(null).map(() => Array(m + 1).fill(0));
    dp[n & 1].fill(1);

    // Bottom-up calculation
    for (let i = n - 1; i >= 0; i--) {
        for (let k = m - 1; k >= 0; k--) {
            dp[i & 1][k] = dp[i & 1][k + 1];
            if (frq[k][target.charCodeAt(i) - 'a'.charCodeAt(0)] > 0) {
                dp[i & 1][k] += (dp[(i + 1) & 1][k + 1] * frq[k][target.charCodeAt(i) - 'a'.charCodeAt(0)]) % mod;
                dp[i & 1][k] %= mod;
            }
        }
        dp[(i + 1) & 1].fill(0);
    }

    return dp[0][0];
};
