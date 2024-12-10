var maximumLength = function(s) {
    const ok = (s, md) => {
        const vis = new Array(26).fill(0); 
        let l = 0;

        for (let r = 0; r < s.length; r++) {
            if (s[r] !== s[l]) {
                l = r; 
            }
            if (r - l + 1 >= md) {
                vis[s.charCodeAt(r) - 'a'.charCodeAt(0)]++;
            }
            if (vis[s.charCodeAt(r) - 'a'.charCodeAt(0)] > 2) {
                return true;
            }
        }

        return false;
    };

    let st = 1, ed = s.length, cur = -1;

    while (st <= ed) {
        const md = Math.floor((st + ed) / 2);
        if (ok(s, md)) {
            cur = md;
            st = md + 1;
        } else {
            ed = md - 1;
        }
    }

    return cur;
};
