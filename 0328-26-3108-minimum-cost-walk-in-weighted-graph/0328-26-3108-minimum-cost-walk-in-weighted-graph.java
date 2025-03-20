public class Solution {
    
    private int find(int u, int[] parent) {
        if (parent[u] != u) {
            parent[u] = find(parent[u], parent);
        }
        return parent[u];
    }
    
    private void join(int u, int v, int w, int[] parent, int[] costs) {
        int rootU = find(u, parent);
        int rootV = find(v, parent);
        costs[rootU] = costs[rootV] = (costs[rootU] & costs[rootV] & w);
        parent[rootV] = rootU;
    }
    
    private int calc(int u, int v, int[] parent, int[] costs) {
        int rootU = find(u, parent);
        int rootV = find(v, parent);
        if (rootU != rootV) {
            return -1;
        }
        return costs[rootU];
    }
    
    public int[] minimumCost(int n, int[][] edges, int[][] queries) {
        int[] parent = new int[n];
        int[] costs = new int[n];
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            costs[i] = -1;
        }
        
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            join(u, v, w, parent, costs);
        }
        
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            result[i] = calc(u, v, parent, costs);
        }
        
        return result;
    }
}
