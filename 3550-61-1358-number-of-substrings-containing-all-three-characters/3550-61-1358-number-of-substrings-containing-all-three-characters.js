
var numberOfSubstrings = function(s) {
    let vis = [-1, -1, -1]; 
    let cnt = 0; 
    for (let i = 0; i < s.length; i++) {
        vis[s.charCodeAt(i) - 'a'.charCodeAt(0)] = i;
        const minIndex = Math.min(...vis);
        cnt += minIndex + 1;
    }

    return cnt;
};