var canConstruct = function(s, k) {
    if (k > s.length) {
        return false;
    }

    let freq = 0;
    for (const ch of s) {
        freq ^= (1 << (ch.charCodeAt(0) - 'a'.charCodeAt(0)));
    }

    return freq.toString(2).split('1').length - 1 <= k;
};
