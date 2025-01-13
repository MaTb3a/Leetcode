var minimumLength = function(s) {
    let mask1 = 0, mask2 = 0;
    let removes = 0;

    for (const ch of s) {
        const bit = 1 << (ch.charCodeAt(0) - 'a'.charCodeAt(0));
        if ((mask1 & bit) === 0) {
            mask1 |= bit;
        } else if ((mask2 & bit) === 0) {
            mask2 |= bit;
        } else {
            removes += 2;
            mask1 &= ~bit;
        }
    }

    return s.length - removes;
};
