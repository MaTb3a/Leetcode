import java.util.*;

class Solution {
    private int d, lst;

    private void dfs(int node, int parent, List<List<Integer>> adj, int dep) {
        if (dep > d) {
            d = dep;
            lst = node;
        }
        for (int child : adj.get(node)) {
            if (child == parent) continue;
            dfs(child, node, adj, dep + 1);
        }
    }

    private int getDiameter(int[][] edges) {
        int n = edges.length + 1;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        d = lst = 0;
        dfs(0, -1, adj, 0);
        d = 0;
        dfs(lst, -1, adj, 0);
        return d;
    }

    private int[] bfs(int src, List<List<Integer>> adj) {
        int n = adj.size();
        Queue<Integer> q = new LinkedList<>();
        q.add(src);
        boolean[] vis = new boolean[n];
        int lst = 0, length = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.poll();
                vis[node] = true;
                lst = node;
                for (int child : adj.get(node)) {
                    if (!vis[child]) q.add(child);
                }
            }
            length++;
        }
        return new int[] { lst, length };
    }

    private int getDiameter2(int[][] edges) {
        int n = edges.length + 1;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        int[] p = bfs(0, adj);
        return bfs(p[0], adj)[1] - 1;
    }

    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        int d1 = getDiameter2(edges1);
        int d2 = getDiameter2(edges2);
        int d1d2 = (int) Math.ceil(d1 / 2.0) + (int) Math.ceil(d2 / 2.0) + 1;
        return Math.max(d1, Math.max(d2, d1d2));
    }
}
