import java.util.*;

class Solution {
    private int[] v;
    private boolean[] vis = new boolean[21];

    private boolean solve(int idx, int n) {
        if (idx == 2 * n - 1) return true;
        if (v[idx] != 0) return solve(idx + 1, n);

        for (int i = n; i >= 1; i--) {
            if (vis[i]) continue;
            int nxt = (i == 1) ? idx : idx + i;
            if (nxt >= v.length || v[nxt] != 0) continue;

            v[idx] = v[nxt] = i;
            vis[i] = true;
            if (solve(idx + 1, n)) return true;
            v[idx] = v[nxt] = 0;
            vis[i] = false;
        }
        return false;
    }

    public int[] constructDistancedSequence(int n) {
        v = new int[2 * n - 1];
        solve(0, n);
        return v;
    }

}
