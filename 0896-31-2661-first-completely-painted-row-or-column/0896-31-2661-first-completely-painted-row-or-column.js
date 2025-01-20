var firstCompleteIndex = function(arr, mat) {
    const n = mat.length, m = mat[0].length;
    const idx = new Array(arr.length + 1).fill(0);

    for (let i = 0; i < arr.length; i++) {
        idx[arr[i]] = i;
    }

    let ans = Infinity;

    for (let i = 0; i < n; i++) {
        let mx = 0;
        for (let j = 0; j < m; j++) {
            mx = Math.max(mx, idx[mat[i][j]]);
        }
        ans = Math.min(ans, mx);
    }

    for (let i = 0; i < m; i++) {
        let mx = 0;
        for (let j = 0; j < n; j++) {
            mx = Math.max(mx, idx[mat[j][i]]);
        }
        ans = Math.min(ans, mx);
    }

    return ans;
};
