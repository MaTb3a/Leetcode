var maxCount = function(banned, n, maxSum) {
    const bannedSet = new Set(banned);  // Convert banned array to a set
    let count = 0;
    
    for (let i = 1; i <= n; i++) {
        if (!bannedSet.has(i) && i <= maxSum) {
            count++;
            maxSum -= i;
        }
    }
    
    return count;
};
