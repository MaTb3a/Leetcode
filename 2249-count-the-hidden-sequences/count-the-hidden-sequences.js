var numberOfArrays = function(differences, lower, upper) {
    let l = 0n;
    let r = 0n;
    let cur = 0n;

    for (const d of differences) {
        cur += BigInt(d);

        l = l < cur ? l : cur;
        r = r > cur ? r : cur;

        if (r - l > BigInt(upper) - BigInt(lower)) {
            return 0;
        }
    }

    const result = (BigInt(upper) - BigInt(lower)) - (r - l) + 1n;
    return Number(result);
};