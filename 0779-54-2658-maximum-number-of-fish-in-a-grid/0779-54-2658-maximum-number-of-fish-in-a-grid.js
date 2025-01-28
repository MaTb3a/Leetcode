var findMaxFish = function(grid) {
    const DFS = (x, y) => {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] === 0) {
            return 0;
        }
        let ans = grid[x][y];
        grid[x][y] = 0;
        return (
            ans +
            DFS(x + 1, y) +
            DFS(x - 1, y) +
            DFS(x, y + 1) +
            DFS(x, y - 1)
        );
    };

    let mx = 0;
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            if (grid[i][j] > 0) {
                mx = Math.max(mx, DFS(i, j));
            }
        }
    }
    return mx;
};
