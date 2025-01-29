var findRedundantConnection = function(edges) {
    let par = Array.from({ length: 1001 }, (_, i) => i);

    function find(u) {
        if (par[u] !== u) {
            par[u] = find(par[u]);
        }
        return par[u];
    }

    function join(u, v) {
        let pu = find(u), pv = find(v);
        if (pu !== pv) {
            par[pu] = pv;
        }
    }

    for (let [u, v] of edges) {
        if (find(u) === find(v)) return [u, v];
        join(u, v);
    }
    
    return [];
};
