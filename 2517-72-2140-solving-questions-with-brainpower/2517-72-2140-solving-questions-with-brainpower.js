var mostPoints = function(questions) {
    const n = questions.length;
    const memo = new Map();
    
    function solve(i) {
        if (i >= n) {
            return 0;
        }
        
        if (memo.has(i)) {
            return memo.get(i);
        }
        
        const skip = solve(i + 1);
        const doSolve = questions[i][0] + solve(i + questions[i][1] + 1);
        
        const result = Math.max(skip, doSolve);
        memo.set(i, result);
        return result;
    }
    
    return solve(0);
};