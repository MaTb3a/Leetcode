function shortestCommonSupersequence(a, b) {
    const n = a.length, m = b.length;
    const dp = Array.from({ length: n + 1 }, () => Array(m + 1).fill(0));
    
    for (let j = 0; j < m; j++) dp[n][j] = m - j;
    for (let i = 0; i < n; i++) dp[i][m] = n - i;
    
    for (let i = n - 1; i >= 0; i--) {
        for (let j = m - 1; j >= 0; j--) {
            if (a[i] === b[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            } else {
                dp[i][j] = Math.min(dp[i + 1][j], dp[i][j + 1]) + 1;
            }
        }
    }
    
    let ans = '';
    let i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] === b[j] && dp[i][j] === dp[i + 1][j + 1] + 1) {
            ans += a[i];
            i++;
            j++;
        } else if (dp[i][j] === dp[i + 1][j] + 1) {
            ans += a[i];
            i++;
        } else {
            ans += b[j];
            j++;
        }
    }
    
    ans += b.substring(j);
    ans += a.substring(i);
    
    return ans;
}