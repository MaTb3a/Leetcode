var getHappyString = function(n, k) {
    let ans = [];
    let total = 3 * (1 << (n - 1));
    if (total < k) return "";
    while (n > 0 && k > 0) {
        total = 1 << (n - 1);
        for (let ch of ['a', 'b', 'c']) {
            if (ans.length > 0 && ans[ans.length - 1] === ch) continue;
            if (k > total) {
                k -= total;
            } else {
                ans.push(ch);
                break;
            }
        }
        n--;
    }
    return ans.join('');
};
