var minOperations = function(boxes) {
    const n = boxes.length;
    let op = 0, L = 0, R = 0;

    for (let i = 0; i < n; i++) {
        if (boxes[i] === '1') {
            op += i;
            R++;
        }
    }

    const result = Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        result[i] = op;
        if (boxes[i] === '1') {
            L++;
            R--;
        }
        op += -R + L;
    }

    return result;
};
