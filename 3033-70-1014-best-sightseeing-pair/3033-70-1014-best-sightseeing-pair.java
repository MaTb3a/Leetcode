class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int n = values.length;
        int mx = 0;
        int dp = values[0];
        for (int j = 1; j < n; j++) {
            mx = Math.max(mx, values[j] - j + dp);
            dp = Math.max(dp, values[j] + j);
        }
        return mx;
    }
}
