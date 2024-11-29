
var minimumTime = function(grid) {
    if (Math.min(grid[0][1], grid[1][0]) > 1) {
        return -1;
    }
    
    const ROWS = grid.length;
    const COLS = grid[0].length;
    const minHeap = new MinPriorityQueue({ priority: x => x[0] });
    minHeap.enqueue([0, 0, 0]); 
    const visited = new Set();
    
    const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    
    while (!minHeap.isEmpty()) {
        const [t, r, c] = minHeap.dequeue().element;
        
        if (r === ROWS - 1 && c === COLS - 1) {
            return t;
        }
        
        for (const [dr, dc] of dirs) {
            const nr = r + dr;
            const nc = c + dc;
            const key = `${nr},${nc}`;
            
            if (nr < 0 || nc < 0 || nr === ROWS || nc === COLS || visited.has(key)) {
                continue;
            }
            
            const wait = Math.abs(grid[nr][nc] - t) % 2 === 0 ? 1 : 0;
            const nTime = Math.max(grid[nr][nc] + wait, t + 1);
            minHeap.enqueue([nTime, nr, nc], nTime);
            visited.add(key);
        }
    }
    return -1;
};