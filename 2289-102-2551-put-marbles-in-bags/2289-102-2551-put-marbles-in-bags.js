var putMarbles = function(weights, k) {
    const n = weights.length;
    const v = [];
    
    for (let i = 1; i < n; i++) {
        v.push(weights[i-1] + weights[i]);
    }
    
    v.sort((a, b) => a - b);
    let ans = 0;
    
    for (let i = 0; i < k-1; i++) {
        ans += v[n-2-i] - v[i];
    }
    
    return ans;
};