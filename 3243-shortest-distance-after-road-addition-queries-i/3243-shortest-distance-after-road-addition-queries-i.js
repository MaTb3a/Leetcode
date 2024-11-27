var shortestDistanceAfterQueries = function(n, queries) {
    const adj = Array.from({ length: n }, () => []);
    
    // Initialize adjacency list
    for (let i = 1; i < n; i++) {
        adj[i - 1].push(i);
    }
    
    const BFS = (n) => {
        const q = [0];
        const dist = Array(n).fill(Infinity);
        dist[0] = 0;
        
        while (q.length > 0) {
            const city = q.shift();
            if (city === n - 1) {
                return dist[city];
            }
            
            for (const child of adj[city]) {
                if (dist[child] > dist[city] + 1) {
                    dist[child] = dist[city] + 1;
                    q.push(child);
                }
            }
        }
        
        return -1;
    };
    
    const result = [];
    for (const [u, v] of queries) {
        adj[u].push(v);
        result.push(BFS(n));
    }
    
    return result;
};
