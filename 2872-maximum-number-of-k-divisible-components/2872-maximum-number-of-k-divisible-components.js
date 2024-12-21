var maxKDivisibleComponents = function(n, edges, values, k) {
    if (n === 1) {
        return 1;
    }

    const adj = Array.from({ length: n }, () => []);
    const degree = Array(n).fill(0);

    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
        degree[u]++;
        degree[v]++;
    }

    const queue = [];
    for (let i = 0; i < n; i++) {
        if (degree[i] === 1) {
            queue.push(i);
        }
    }

    let ans = 0;
    while (queue.length) {
        const node = queue.shift();
        degree[node]--;
        if (values[node] % k === 0) {
            ans++;
        }

        for (const child of adj[node]) {
            degree[child]--;
            values[child] = (values[child] + values[node]) % k;
            if (degree[child] === 1) {
                queue.push(child);
            }
        }
    }

    return ans;
};
