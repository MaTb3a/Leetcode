/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
var closestPrimes = function(left, right) {
        const vis = new Array(right + 1).fill(false);
        vis[0] = vis[1] = true;
        for (let i = 2; i * i <= right; i++) {
            if (!vis[i]) {
                for (let j = i + i; j <= right; j += i) {
                    vis[j] = true;
                }
            }
        }

        let a = -1, b = -1;
        let lst = -1;
        let minGap = Infinity;
        for (let i = left; i <= right; i++) {
            if (vis[i]) continue;
            if (lst !== -1 && i - lst < minGap) {
                minGap = i - lst;
                a = lst;
                b = i;
            }
            lst = i;
        }
        return [a, b];
    

};