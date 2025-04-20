var numRabbits = function(answers) {
    const frq = {};
    for (const a of answers) 
        frq[a] = (frq[a] || 0) + 1;
    
    let ans = 0;
    for (const k in frq) 
        ans += Math.ceil(frq[k]/ (parseInt(k) + 1)) * (parseInt(k) + 1);

    return ans;
};