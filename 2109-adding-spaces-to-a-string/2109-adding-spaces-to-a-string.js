var addSpaces = function(s, spaces) {
    const result = [];
    const spaceSet = new Set(spaces);

    for (let i = 0; i < s.length; i++) {
        if (spaceSet.has(i)) {
            result.push(" ");
        }
        result.push(s[i]);
    }

    return result.join("");
};
