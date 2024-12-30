class Solution {
    public int countGoodStrings(int low, int high, int zero, int one) {
        final int MOD = 1000000007;
        int[] dp = new int[high + 1];

        for (int i = low; i <= high; i++) {
            dp[i] = 1;
        }

        for (int i = high; i >= 0; i--) {
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
    }
}
