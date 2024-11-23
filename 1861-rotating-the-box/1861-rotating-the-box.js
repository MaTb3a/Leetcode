var rotateTheBox = function(box) {
    const n = box.length;
    const m = box[0].length;

    // Create the rotated box with dimensions swapped
    const rotatedBox = Array.from({ length: m }, () => Array(n).fill('.'));

    for (let i = 0; i < n; i++) {
        let lastStone = m - 1;
        for (let j = m - 1; j >= 0; j--) {
            if (box[i][j] === '*') {
                lastStone = j - 1;
                rotatedBox[j][n - i - 1] = '*';
            } else if (box[i][j] === '#') {
                rotatedBox[lastStone][n - i - 1] = '#';
                lastStone--;
            }
        }
    }

    return rotatedBox;
};
