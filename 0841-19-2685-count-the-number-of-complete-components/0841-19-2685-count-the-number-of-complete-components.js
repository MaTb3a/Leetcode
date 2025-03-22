/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var countCompleteComponents = function(n, edges) {
    const vis = new Array(n).fill(false);
    const adj = Array.from({ length: n }, () => []);
    let sz;
    
    for (const [a, b] of edges) {
        adj[a].push(b);
        adj[b].push(a);
    }
    
    function dfs(u) {
        vis[u] = true;
        let ret = 1;
        sz &= adj[u].length;
        
        for (const ch of adj[u]) {
            if (!vis[ch]) {
                ret += dfs(ch);
            }
        }
        
        return ret;
    }
    
    let cnt = 0;
    for (let i = 0; i < n; i++) {
        if (vis[i]) continue;
        sz = adj[i].length;
        cnt += (dfs(i) === sz + 1) ? 1 : 0;
    }
    
    return cnt;
};