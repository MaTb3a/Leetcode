var removeOccurrences = function(s, part) {
    const kmp = (part) => {
        let lps = Array(part.length).fill(0);
        let j = 0;
        for (let i = 1; i < part.length; i++) {
            while (j && part[i] !== part[j]) j = lps[j - 1];
            if (part[i] === part[j]) lps[i] = ++j;
        }
        return lps;
    };

    let lps = kmp(part);
    let sz = part.length;
    let ans = [];
    let stk = [];
    let j = 0;

    for (let ch of s) {
        ans.push(ch);
        stk.push(j);

        while (j && ch !== part[j]) j = lps[j - 1];

        if (ch === part[j]) j++;

        stk[stk.length - 1] = j;

        if (j === sz) {
            ans.length -= sz;
            stk.length -= sz;
            j = stk.length ? stk[stk.length - 1] : 0;
        }
    }

    return ans.join('');
};
