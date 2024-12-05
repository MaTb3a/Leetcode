var canChange = function(start, target) {
    const n = start.length;
    let i = 0, j = 0;
    
    while (i < n || j < n) {
        while (i < n && start[i] === '_') {
            i++;
        }
        while (j < n && target[j] === '_') {
            j++;
        }
        
        if (i === n && j === n) {
            return true;
        }
        
        if (i === n || j === n || start[i] !== target[j]) {
            return false;
        }
        
        if (start[i] === 'L' && i < j) {  // L can only move left
            return false;
        }
        if (start[i] === 'R' && i > j) {  // R can only move right
            return false;
        }
        
        i++;
        j++;
    }
    
    return true;
};
