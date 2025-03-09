/**
 * @param {number[]} colors
 * @param {number} k
 * @return {number}
 */
var numberOfAlternatingGroups = function(colors, k) {
        const n = colors.length;
        let cnt = 1;
        let ans = 0;
        for (let i = 1; i < n + k - 1; i++) {
            const idx = i >= n ? i - n : i;
            const prevIdx = i - 1 >= n ? (i - 1) - n : i - 1;
            cnt = colors[idx] !== colors[prevIdx] ? cnt + 1 : 1;
            ans += cnt >= k ? 1 : 0;
        }
        return ans;
    

};