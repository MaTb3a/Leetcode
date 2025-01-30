import java.util.*;

class Solution {
    private boolean dfs(int node, boolean c, List<List<Integer>> adj, int[] color, List<Integer> v) {
        color[node] = c ? 1 : 0;
        v.add(node);
        for (int child : adj.get(node)) {
            if (color[child] == (c ? 1 : 0)) return false;
            if (color[child] == -1 && !dfs(child, !c, adj, color, v)) return false;
        }
        return true;
    }

    private int bfs(List<Integer> v, List<List<Integer>> adj, int n) {
        int mx = 0;
        for (int st : v) {
            Queue<Integer> q = new LinkedList<>();
            q.offer(st);
            int[] dist = new int[n + 1];
            Arrays.fill(dist, -1);
            dist[st] = 0;
            while (!q.isEmpty()) {
                int node = q.poll();
                for (int child : adj.get(node)) {
                    if (dist[child] != -1) continue;
                    dist[child] = dist[node] + 1;
                    mx = Math.max(mx, dist[child]);
                    q.offer(child);
                }
            }
        }
        return mx + 1;
    }

    public int magnificentSets(int n, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) adj.add(new ArrayList<>());
        int[] color = new int[n + 1];
        Arrays.fill(color, -1);
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (color[i] != -1) continue;
            List<Integer> v = new ArrayList<>();
            if (!dfs(i, false, adj, color, v)) return -1;
            ans += bfs(v, adj, n);
        }
        return ans;
    }
}