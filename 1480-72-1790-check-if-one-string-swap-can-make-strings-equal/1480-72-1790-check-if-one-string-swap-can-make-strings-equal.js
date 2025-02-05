var areAlmostEqual = function(s1, s2) {
    let diff = [];
    
    for (let i = 0; i < s1.length; i++) {
        if (s1[i] !== s2[i]) diff.push([s1[i], s2[i]]);
    }
    
    return diff.length === 0 || (diff.length === 2 && diff[0].reverse().toString() === diff[1].toString());
};
