/**
 * @param {string} s
 * @return {number[]}
 */
var partitionLabels = function(s) {
    const lastIndex = new Array(26).fill(0);
    
    for (let i = 0; i < s.length; i++) {
        lastIndex[s.charCodeAt(i) - 'a'.charCodeAt(0)] = i;
    }
    
    const result = [];
    let start = 0;
    let end = 0;
    
    for (let i = 0; i < s.length; i++) {
        end = Math.max(end, lastIndex[s.charCodeAt(i) - 'a'.charCodeAt(0)]);
        
        if (end === i) {
            result.push(end - start + 1);
            start = end + 1;
        }
    }
    
    return result;
};