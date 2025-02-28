class Solution {
    public String shortestCommonSupersequence(String a, String b) {
        int n = a.length(), m = b.length();
        int[][] dp = new int[n + 1][m + 1];
        
        for (int j = 0; j < m; j++) dp[n][j] = m - j;
        for (int i = 0; i < n; i++) dp[i][m] = n - i;
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (a.charAt(i) == b.charAt(j)) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                } else {
                    dp[i][j] = Math.min(dp[i + 1][j], dp[i][j + 1]) + 1;
                }
            }
        }
        
        StringBuilder ans = new StringBuilder();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a.charAt(i) == b.charAt(j) && dp[i][j] == dp[i + 1][j + 1] + 1) {
                ans.append(a.charAt(i));
                i++;
                j++;
            } else if (dp[i][j] == dp[i + 1][j] + 1) {
                ans.append(a.charAt(i));
                i++;
            } else {
                ans.append(b.charAt(j));
                j++;
            }
        }
        
        ans.append(b.substring(j));
        ans.append(a.substring(i));
        
        return ans.toString();
    }
}