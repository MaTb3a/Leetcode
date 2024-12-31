import java.util.*;

class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int lst = days[days.length - 1];
        int[] dp = new int[lst + 1];

        Set<Integer> daySet = new HashSet<>();
        for (int day : days) {
            daySet.add(day);
        }

        for (int d = 1; d <= lst; d++) {
            if (!daySet.contains(d)) {
                dp[d] = dp[d - 1];
                continue;
            }
            int ch1 = costs[0] + dp[d - 1];
            int ch2 = costs[1] + dp[Math.max(0, d - 7)];
            int ch3 = costs[2] + dp[Math.max(0, d - 30)];
            dp[d] = Math.min(ch1, Math.min(ch2, ch3));
        }

        return dp[lst];
    }
}
