var canMakeSubsequence = function(str1, str2) {
    let j = 0;
    for (const c of str1) {
        if (j < str2.length && (c === str2[j] || c.charCodeAt(0) - str2[j].charCodeAt(0) === 25 || c.charCodeAt(0) - str2[j].charCodeAt(0) === -1)) {
            j++;
        }
    }
    return j === str2.length;
};
