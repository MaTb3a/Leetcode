
var countPaths = function(n, roads) {
    const mod = 1e9 + 7;
    
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v, t] of roads) {
        adj[u].push([v, t]);
        adj[v].push([u, t]);
    }
    
    const dist = Array(n).fill(Number.MAX_SAFE_INTEGER);
    const ways = Array(n).fill(0);
    dist[0] = 0;
    ways[0] = 1;
    
    const visited = Array(n).fill(false);
    
    for (let i = 0; i < n; i++) {
        let minDist = Number.MAX_SAFE_INTEGER;
        let minNode = -1;
        
        for (let j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                minNode = j;
            }
        }
        
        if (minNode === -1) break;
        visited[minNode] = true;
        
        for (const [v, t] of adj[minNode]) {
            if (visited[v]) continue;
            
            if (dist[v] > dist[minNode] + t) {
                dist[v] = dist[minNode] + t;
                ways[v] = ways[minNode];
            } else if (dist[v] === dist[minNode] + t) {
                ways[v] = (ways[v] + ways[minNode]) % mod;
            }
        }
    }
    
    return ways[n-1];
};