/**
 * @param {string} blocks
 * @param {number} k
 * @return {number}
 */
var minimumRecolors = function(blocks, k) {
    let w = 0;
        for (let i = 0; i < k; i++) {
            if (blocks[i] === 'W') w++;
        }
        let ans = w;
        for (let i = k; i < blocks.length; i++) {
            w += (blocks[i] === 'W' ? 1 : 0) - (blocks[i - k] === 'W' ? 1 : 0);
            ans = Math.min(ans, w);
        }
        return ans;

};