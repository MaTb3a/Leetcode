class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length;
        int cnt = 1;
        int ans = 0;
        for (int i = 1; i < n + k - 1; i++) {
            int idx = (i >= n) ? i - n : i;
            int prevIdx = (i - 1 >= n) ? (i - 1) - n : (i - 1);
            cnt = (colors[idx] != colors[prevIdx]) ? cnt + 1 : 1;
            ans += (cnt >= k) ? 1 : 0;
        }
        return ans;
    }
}