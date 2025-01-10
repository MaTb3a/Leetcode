var wordSubsets = function(words1, words2) {
    const solve = (s) => {
        const freq = Array(26).fill(0);
        for (const ch of s) {
            freq[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }
        return freq;
    };

    const frq = Array(26).fill(0);
    for (const word of words2) {
        const tmp = solve(word);
        for (let i = 0; i < 26; i++) {
            frq[i] = Math.max(frq[i], tmp[i]);
        }
    }

    const result = [];
    for (const word of words1) {
        const tmp = solve(word);
        if (frq.every((count, i) => count <= tmp[i])) {
            result.push(word);
        }
    }

    return result;
};
