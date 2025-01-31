var largestIsland = function(grid) {
    const n = grid.length;
    const directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    
    const dfs = (x, y, islandId) => {
        if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] !== 1) return 0;
        grid[x][y] = islandId;
        let size = 1;
        for (const [dx, dy] of directions) {
            size += dfs(x + dx, y + dy, islandId);
        }
        return size;
    };

    let islandId = 2;
    const islandSizes = {};
    let maxIsland = 0;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                islandSizes[islandId] = dfs(i, j, islandId);
                maxIsland = Math.max(maxIsland, islandSizes[islandId]);
                islandId++;
            }
        }
    }

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 0) {
                let uniqueIslands = new Set();
                for (const [dx, dy] of directions) {
                    const ni = i + dx, nj = j + dy;
                    if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] > 1) {
                        uniqueIslands.add(grid[ni][nj]);
                    }
                }
                let newSize = 1 + [...uniqueIslands].reduce((sum, id) => sum + islandSizes[id], 0);
                maxIsland = Math.max(maxIsland, newSize);
            }
        }
    }

    return maxIsland;
};
