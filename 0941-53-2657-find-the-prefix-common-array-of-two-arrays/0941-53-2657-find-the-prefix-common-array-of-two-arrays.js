var findThePrefixCommonArray = function(A, B) {
    const vis = Array(51).fill(0);
    const vis2 = Array(51).fill(0);
    const result = [];

    for (let i = 0; i < A.length; i++) {
        vis[A[i]] = 1;
        vis2[B[i]] = 1;
        let count = 0;
        for (let j = 0; j <= 50; j++) {
            if (vis[j] && vis2[j]) {
                count++;
            }
        }
        result.push(count);
    }

    return result;
};
