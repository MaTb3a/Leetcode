var bfs = function (src, adj) {
    const n = adj.length;
    const q = [src];
    const vis = Array(n).fill(false);
    let lst = 0, length = 0;

    while (q.length) {
        const size = q.length;
        for (let i = 0; i < size; i++) {
            const node = q.shift();
            vis[node] = true;
            lst = node;
            for (const child of adj[node]) {
                if (!vis[child]) q.push(child);
            }
        }
        length++;
    }
    return [lst, length];
};

var getDiameter2 = function (edges) {
    const n = edges.length + 1;
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }
    const [lst] = bfs(0, adj);
    const [, length] = bfs(lst, adj);
    return length - 1;
};

var minimumDiameterAfterMerge = function (edges1, edges2) {
    const d1 = getDiameter2(edges1);
    const d2 = getDiameter2(edges2);
    const d1d2 = Math.ceil(d1 / 2) + Math.ceil(d2 / 2) + 1;
    return Math.max(d1, d2, d1d2);
};
