class Solution {
    public int countPaths(int n, int[][] roads) {
        final int mod = 1000000007;
        List<int[]>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        
        for (int[] road : roads) {
            int u = road[0], v = road[1], t = road[2];
            adj[u].add(new int[]{v, t});
            adj[v].add(new int[]{u, t});
        }
        
        long[] dist = new long[n];
        int[] ways = new int[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        ways[0] = 1;
        
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));
        pq.offer(new long[]{0, 0}); 
        
        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            long time = curr[0];
            int u = (int) curr[1];
            
            if (time > dist[u]) continue;
            
            for (int[] next : adj[u]) {
                int v = next[0], t = next[1];
                
                if (dist[v] > time + t) {
                    dist[v] = time + t;
                    pq.offer(new long[]{dist[v], v});
                    ways[v] = ways[u];
                } else if (dist[v] == time + t) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }
        
        return ways[n-1];
    }
}