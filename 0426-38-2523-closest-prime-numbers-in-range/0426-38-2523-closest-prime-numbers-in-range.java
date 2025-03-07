import java.util.Arrays;

class Solution {
    boolean[] vis;

    public int[] closestPrimes(int left, int right) {
        sieve(right);
        int a = -1, b = -1;
        int lst = -1;
        int minGap = Integer.MAX_VALUE;
        for (int i = left; i <= right; i++) {
            if (vis[i]) continue;
            if (lst != -1 && i - lst < minGap) {
                minGap = i - lst;
                a = lst;
                b = i;
            }
            lst = i;
        }
        return new int[]{a, b};
    }

    private void sieve(int n) {
        vis = new boolean[n + 1];
        vis[0] = vis[1] = true;
        for (int i = 2; i * i <= n; i++) {
            if (!vis[i]) {
                for (int j = i + i; j <= n; j += i) {
                    vis[j] = true;
                }
            }
        }
    }
}