var shiftingLetters = function(s, shifts) {
    const n = s.length;
    const v = Array(n + 1).fill(0);

    for (const [l, r, d] of shifts) {
        v[l] += d === 1 ? 1 : -1;
        if (r + 1 < n) {
            v[r + 1] += d === 1 ? -1 : 1;
        }
    }

    const chars = s.split('');
    for (let i = 0; i < n; i++) {
        if (i > 0) {
            v[i] += v[i - 1];
        }
        chars[i] = String.fromCharCode(((chars[i].charCodeAt(0) - 'a'.charCodeAt(0) + v[i]) % 26 + 26) % 26 + 'a'.charCodeAt(0));
    }

    return chars.join('');
};
