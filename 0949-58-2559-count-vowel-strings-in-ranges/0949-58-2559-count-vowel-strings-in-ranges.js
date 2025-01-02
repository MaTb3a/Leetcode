var vowelStrings = function(words, queries) {
    const isVowel = (ch) => 'aeiou'.includes(ch);

    const n = words.length;
    const pre = Array(n).fill(0);

    for (let i = 0; i < n; i++) {
        pre[i] = isVowel(words[i][0]) && isVowel(words[i][words[i].length - 1]) ? 1 : 0;
        if (i > 0) {
            pre[i] += pre[i - 1];
        }
    }

    return queries.map(([l, r]) => pre[r] - (l > 0 ? pre[l - 1] : 0));
};
