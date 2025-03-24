class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> a[0] - b[0]);
        int d = 0;
        int ans = 0;
        for (int[] meet : meetings) {
            int start = meet[0];
            int end = meet[1];
            if (start > d) {
                ans += start - d - 1;
            }
            d = Math.max(d, end);
        }
        return ans + (days - d);

    }
}