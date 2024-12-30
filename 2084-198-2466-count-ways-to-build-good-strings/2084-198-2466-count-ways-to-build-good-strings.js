var countGoodStrings = function(low, high, zero, one) {
    const MOD = 1e9 + 7;
    const dp = Array(high + 1).fill(0);

    for (let i = low; i <= high; i++) {
        dp[i] = 1;
    }

    for (let i = high; i >= 0; i--) {
        if (i + zero <= high) {
            dp[i] += dp[i + zero];
            dp[i] %= MOD;
        }
        if (i + one <= high) {
            dp[i] += dp[i + one];
            dp[i] %= MOD;
        }
    }

    return dp[0];
};
