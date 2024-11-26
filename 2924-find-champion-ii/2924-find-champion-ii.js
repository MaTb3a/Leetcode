var findChampion = function(n, edges) {
    const visited = Array(n).fill(false);
    for (const [u, v] of edges) {
        visited[v] = true;
    }
    
    let champion = -1;
    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            if (champion === -1) {
                champion = i;
            } else {
                return -1;
            }
        }
    }
    
    return champion;
};
