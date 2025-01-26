import java.util.*;

class Solution {
    public int maximumInvitations(int[] favorite) {
        int n = favorite.length;
        int[] deg = new int[n];
        for (int fav : favorite) {
            deg[fav]++;
        }

        Queue<Integer> q = new LinkedList<>();
        int[] chain = new int[n];
        Arrays.fill(chain, 1);

        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                q.add(i);
            }
        }

        while (!q.isEmpty()) {
            int x = q.poll();
            int y = favorite[x];
            chain[y] = Math.max(chain[y], chain[x] + 1);
            deg[y]--;
            if (deg[y] == 0) {
                q.add(y);
            }
        }

        int mx = 0, meetings = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                continue;
            }
            int cur = i, length = 0;
            while (deg[cur] > 0) {
                length++;
                deg[cur] = 0;
                cur = favorite[cur];
            }
            if (length > 2) {
                mx = Math.max(mx, length);
            } else {
                meetings += chain[i] + chain[favorite[i]];
            }
        }

        return Math.max(mx, meetings);
    }
}
