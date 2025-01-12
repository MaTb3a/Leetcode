var canBeValid = function(s, locked) {
    const solve = (s, locked, forward) => {
        let cnt = 0, magic = 0;
        const n = s.length;

        for (let i = 0; i < n; i++) {
            const idx = forward ? i : n - i - 1;

            if (locked[idx] === '0') {
                magic++;
                continue;
            }

            if ((s[idx] === '(' && forward) || (s[idx] === ')' && !forward)) {
                cnt++;
            } else {
                if (cnt > 0) {
                    cnt--;
                } else if (magic > 0) {
                    magic--;
                } else {
                    return false;
                }
            }
        }

        return true;
    };

    if (s.length % 2 !== 0) {
        return false;
    }
    return solve(s, locked, true) && solve(s, locked, false);
};
