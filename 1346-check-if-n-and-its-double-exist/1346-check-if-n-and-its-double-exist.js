var checkIfExist = function(arr) {
    const seen = new Set();
    for (const num of arr) {
        if (seen.has(num * 2) || (num % 2 === 0 && seen.has(num / 2))) {
            return true;
        }
        seen.add(num);
    }
    return false;
};
