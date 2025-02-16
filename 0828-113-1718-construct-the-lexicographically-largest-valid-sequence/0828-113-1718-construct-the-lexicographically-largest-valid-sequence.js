var constructDistancedSequence = function(n) {
    let v = new Array(2 * n - 1).fill(0);
    let vis = new Array(n + 1).fill(false);

    function solve(idx) {
        if (idx === 2 * n - 1) return true;
        if (v[idx] !== 0) return solve(idx + 1);

        for (let i = n; i >= 1; i--) {
            if (vis[i]) continue;
            let nxt = i === 1 ? idx : idx + i;
            if (nxt >= v.length || v[nxt] !== 0) continue;

            v[idx] = v[nxt] = i;
            vis[i] = true;

            if (solve(idx + 1)) return true;

            v[idx] = v[nxt] = 0;
            vis[i] = false;
        }
        return false;
    }

    solve(0);
    return v;
};
