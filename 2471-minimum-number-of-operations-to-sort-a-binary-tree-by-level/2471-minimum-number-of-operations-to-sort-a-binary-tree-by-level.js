var minimumOperations = function(root) {
    const q = [root];
    let swp = 0;

    while (q.length) {
        const n = q.length;
        const v = [];
        
        for (let i = 0; i < n; i++) {
            const cur = q.shift();
            v.push(cur.val);
            if (cur.left) q.push(cur.left);
            if (cur.right) q.push(cur.right);
        }
        
        const sorted = [...v].sort((a, b) => a - b);
        const idxMap = new Map();
        for (let i = 0; i < n; i++) {
            idxMap.set(v[i], i);
        }
        
        for (let i = 0; i < n; i++) {
            if (v[i] !== sorted[i]) {
                const idx = idxMap.get(sorted[i]);
                idxMap.set(v[i], idx);
                [v[i], v[idx]] = [v[idx], v[i]];
                swp++;
            }
        }
    }
    
    return swp;
};
