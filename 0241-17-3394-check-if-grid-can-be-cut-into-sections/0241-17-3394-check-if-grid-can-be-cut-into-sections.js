/**
 * @param {number} n
 * @param {number[][]} rectangles
 * @return {boolean}
 */
var checkValidCuts = function(n, rectangles) {
    function check(rectangles, d) {
        rectangles.sort((a, b) => a[d] - b[d]);
        let cnt = 0;
        let mx = rectangles[0][d + 2];
        for (let i = 1; i < rectangles.length; i++) {
            if (mx <= rectangles[i][d]) {
                cnt++;
            }
            mx = Math.max(mx, rectangles[i][d + 2]);
        }
        return cnt >= 2;
    }
    
    return check(rectangles, 0) || check(rectangles, 1);

};