var countPalindromicSubsequence = function(s) {
    const left = Array(26).fill(-1);
    const right = Array(26).fill(0);

    for (let i = 0; i < s.length; i++) {
        const idx = s.charCodeAt(i) - 'a'.charCodeAt(0);
        if (left[idx] === -1) {
            left[idx] = i;
        } else {
            right[idx] = i;
        }
    }

    let ans = 0;
    for (let i = 0; i < 26; i++) {
        if (right[i] === 0) continue;
        const visited = new Set();
        for (let j = left[i] + 1; j < right[i]; j++) {
            visited.add(s[j]);
        }
        ans += visited.size;
    }

    return ans;
};
