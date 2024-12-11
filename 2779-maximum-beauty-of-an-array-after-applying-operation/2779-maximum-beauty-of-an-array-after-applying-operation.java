
class Solution {
    public int maximumBeauty(int[] nums, int k) {
        int mx = Arrays.stream(nums).max().getAsInt();

        int[] vis = new int[mx + 2];

        for (int x : nums) {
            vis[Math.max(0, x - k)]++;
            vis[Math.min(x + k + 1, mx + 1)]--;
        }

        int ans = 0, cnt = 0;
        for (int x : vis) {
            cnt += x;
            ans = Math.max(ans, cnt);
        }

        return ans;
    }
}
