var minCost = function(grid) {
    const n = grid.length, m = grid[0].length;
    const dx = [0, 0, 1, -1];
    const dy = [1, -1, 0, 0];
    const dist = Array.from({ length: n }, () => Array(m).fill(Infinity));
    dist[0][0] = 0;
    const q = [[0, 0]];

    while (q.length > 0) {
        const [x, y] = q.shift();
        for (let i = 0; i < 4; i++) {
            const ddx = x + dx[i], ddy = y + dy[i];
            if (ddx >= 0 && ddy >= 0 && ddx < n && ddy < m) {
                const newCost = dist[x][y] + (grid[x][y] === i + 1 ? 0 : 1);
                if (dist[ddx][ddy] > newCost) {
                    dist[ddx][ddy] = newCost;
                    q.push([ddx, ddy]);
                }
            }
        }
    }

    return dist[n - 1][m - 1];
};
