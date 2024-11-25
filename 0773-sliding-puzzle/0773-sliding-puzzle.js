var slidingPuzzle = function(board) {
    const directions = [
        [1, 3],     // 0
        [0, 2, 4],  // 1
        [1, 5],     // 2
        [0, 4],     // 3
        [1, 3, 5],  // 4
        [2, 4]      // 5
    ];

    const target = "123450";
    const start = board.flat().join("");
    const visited = new Map();
    const queue = [[start.indexOf("0"), start]];
    visited.set(start, 0);

    while (queue.length > 0) {
        const [zeroPos, state] = queue.shift();
        if (state === target) {
            return visited.get(state);
        }

        for (const neighbor of directions[zeroPos]) {
            const newState = state.split("");
            [newState[zeroPos], newState[neighbor]] = [newState[neighbor], newState[zeroPos]];
            const newStateStr = newState.join("");

            if (!visited.has(newStateStr)) {
                visited.set(newStateStr, visited.get(state) + 1);
                queue.push([neighbor, newStateStr]);
            }
        }
    }

    return -1;
};
