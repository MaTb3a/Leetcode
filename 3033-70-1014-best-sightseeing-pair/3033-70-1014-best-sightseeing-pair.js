var maxScoreSightseeingPair = function(values) {
    const n = values.length;
    let mx = 0;
    let dp = values[0];
    for (let j = 1; j < n; j++) {
        mx = Math.max(mx, values[j] - j + dp);
        dp = Math.max(dp, values[j] + j);
    }
    return mx;
};
