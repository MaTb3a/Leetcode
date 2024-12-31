var mincostTickets = function(days, costs) {
    const lst = days[days.length - 1];
    const dp = Array(lst + 1).fill(0);

    const daySet = new Set(days);

    for (let d = 1; d <= lst; d++) {
        if (!daySet.has(d)) {
            dp[d] = dp[d - 1];
            continue;
        }
        const ch1 = costs[0] + dp[d - 1];
        const ch2 = costs[1] + dp[Math.max(0, d - 7)];
        const ch3 = costs[2] + dp[Math.max(0, d - 30)];
        dp[d] = Math.min(ch1, ch2, ch3);
    }

    return dp[lst];
};
