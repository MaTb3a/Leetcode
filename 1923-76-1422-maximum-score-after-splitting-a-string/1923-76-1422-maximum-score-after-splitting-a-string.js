var maxScore = function(s) {
    let zeros = 0;
    let ones = [...s].filter(ch => ch === '1').length;
    let ans = 0;

    for (let i = 0; i < s.length - 1; i++) {
        if (s[i] === '1') {
            ones--;
        } else {
            zeros++;
        }
        ans = Math.max(ans, ones + zeros);
    }

    return ans;
};
