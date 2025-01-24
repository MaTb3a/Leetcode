var eventualSafeNodes = function(graph) {
    const n = graph.length;
    const state = Array(n).fill(0); 
    const ans = [];
    
    const dfs = (u) => {
        if (state[u] !== 0) return state[u] === 1;
        state[u] = 2;
        for (const child of graph[u]) {
            if (!dfs(child)) return false;
        }
        state[u] = 1;
        return true;
    };

    for (let i = 0; i < n; i++) {
        if (dfs(i)) ans.push(i);
    }
    return ans;
};
