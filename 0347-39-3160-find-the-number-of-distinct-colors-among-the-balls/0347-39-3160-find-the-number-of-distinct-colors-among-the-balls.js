var queryResults = function(limit, queries) {
    let n = queries.length;
    let result = new Array(n);
    let ballColorMap = new Map();
    let colorCount = new Map();

    for (let i = 0; i < n; i++) {
        let [ball, color] = queries[i];

        if (ballColorMap.has(ball)) {
            let oldColor = ballColorMap.get(ball);
            colorCount.set(oldColor, colorCount.get(oldColor) - 1);
            if (colorCount.get(oldColor) === 0) colorCount.delete(oldColor);
        }

        colorCount.set(color, (colorCount.get(color) || 0) + 1);
        ballColorMap.set(ball, color);
        result[i] = colorCount.size;
    }

    return result;
};
