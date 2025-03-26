
var minOperations = function(grid, x) {
    const mod = grid[0][0] % x;
    const sz = grid.length * grid[0].length;
    const frq = new Array(10001).fill(0);
    
    for (let row of grid) {
        for (let val of row) {
            if (val % x !== mod) {
                return -1;
            }
            frq[val]++;
        }
    }
    
    let md = 0, ans = 0;
    for (let i = 0; i < 10001; i++) {
        ans += frq[i];
        if (ans * 2 >= sz) {
            md = i;
            break;
        }
    }
    
    ans = 0;
    for (let i = 0; i < 10001; i++) {
        ans += Math.abs(i - md) * frq[i];
    }
    
    return Math.floor(ans / x);
};