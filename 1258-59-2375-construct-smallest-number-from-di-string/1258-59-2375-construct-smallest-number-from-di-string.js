var smallestNumber = function(pattern) {
    let n = pattern.length, stk = [], ans = [];
    for (let i = 0; i <= n; i++) {
        stk.push((i + 1).toString());
        if (i === n || pattern[i] === 'I') {
            while (stk.length) ans.push(stk.pop());
        }
    }
    return ans.join('');
};
