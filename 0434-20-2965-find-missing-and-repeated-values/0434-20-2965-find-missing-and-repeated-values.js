/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var findMissingAndRepeatedValues = function(grid) {
    let n = grid.length;
        let a = 0;
        let gsum = 0;
        for (let row of grid) {
            for (let x of row) {
                let nx = Math.abs(x);
                gsum += nx;
                let r = Math.floor((nx - 1) / n);
                let c = (nx - 1) % n;
                if (grid[r][c] < 0) {
                    a = nx;
                }
                grid[r][c] *= -1;
            }
        }
        let nSquared = n * n;
        let totalSum = (nSquared * (nSquared + 1)) / 2;
        return [a, totalSum - gsum + a];

};