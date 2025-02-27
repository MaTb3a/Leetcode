import java.util.HashMap;
import java.util.Map;

class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        int n = arr.length;
        int[][] dp = new int[n][n];
        Map<Integer, Integer> mp = new HashMap<>();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            mp.put(arr[i], i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int nextVal = arr[i] + arr[j];
                if (mp.containsKey(nextVal)) {
                    int nextIdx = mp.get(nextVal);
                    dp[j][nextIdx] = dp[i][j] + 1;
                    ans = Math.max(ans, dp[j][nextIdx]);
                }
            }
        }

        return ans > 0 ? ans + 2 : 0;
    }
}