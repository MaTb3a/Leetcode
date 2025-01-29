import java.util.*;

class Solution {
    private int[] par = new int[1001];

    private int find(int u) {
        if (par[u] != u) {
            par[u] = find(par[u]);
        }
        return par[u];
    }

    private void join(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            par[pu] = pv;
        }
    }

    public int[] findRedundantConnection(int[][] edges) {
        for (int i = 0; i < 1001; i++) {
            par[i] = i;
        }

        for (int[] edge : edges) {
            if (find(edge[0]) == find(edge[1])) {
                return edge;
            }
            join(edge[0], edge[1]);
        }

        return new int[]{};
    }
}
