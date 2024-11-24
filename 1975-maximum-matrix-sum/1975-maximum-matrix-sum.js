var maxMatrixSum = function(matrix) {
    let totalSum = 0;
    let minValue = Infinity;
    let negativeCount = 0;

    for (const row of matrix) {
        for (const x of row) {
            totalSum += Math.abs(x);
            minValue = Math.min(minValue, Math.abs(x));
            if (x < 0) {
                negativeCount++;
            }
        }
    }

    return totalSum - (negativeCount % 2 !== 0 ? 2 * minValue : 0);
};
