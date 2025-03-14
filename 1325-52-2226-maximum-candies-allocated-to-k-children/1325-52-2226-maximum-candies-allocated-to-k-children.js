/**
 * @param {number[]} candies
 * @param {number} k
 * @return {number}
 */
var maximumCandies = function(candies, k) {
    const ok = (md) => {
            let cnt = 0;
            for (const x of candies) {
                cnt += Math.floor(x / md);
            }
            return cnt >= k;
        };

        let st = 1;
        let ed = Math.max(...candies);
        let cur = 0;

        while (st <= ed) {
            const md = Math.floor((st + ed) / 2);
            if (ok(md)) {
                cur = md;
                st = md + 1;
            } else {
                ed = md - 1;
            }
        }
        return cur;
    
};