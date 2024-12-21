import java.util.*;

class Solution {
    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        if (n == 1) {
            return 1;
        }

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        int[] degree = new int[n];
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.add(i);
            }
        }

        int ans = 0;
        while (!q.isEmpty()) {
            int node = q.poll();
            degree[node]--;
            if (values[node] % k == 0) {
                ans++;
            }

            for (int child : adj.get(node)) {
                degree[child]--;
                values[child] += values[node];
                values[child] %= k;
                if (degree[child] == 1) {
                    q.add(child);
                }
            }
        }

        return ans;
    }
}
