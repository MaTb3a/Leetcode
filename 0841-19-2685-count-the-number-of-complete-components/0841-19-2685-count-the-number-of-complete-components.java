class Solution {
    private boolean[] vis;
    private List<Integer>[] adj;
    private int sz;
    
    public int countCompleteComponents(int n, int[][] edges) {
        vis = new boolean[n];
        adj = new ArrayList[n];
        
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        
        for (int[] edge : edges) {
            adj[edge[0]].add(edge[1]);
            adj[edge[1]].add(edge[0]);
        }
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            sz = adj[i].size();
            cnt += (dfs(i) == sz + 1) ? 1 : 0;
        }
        
        return cnt;
    }
    
    private int dfs(int u) {
        vis[u] = true;
        int ret = 1;
        sz &= adj[u].size();
        
        for (int ch : adj[u]) {
            if (!vis[ch]) {
                ret += dfs(ch);
            }
        }
        
        return ret;
    }
}