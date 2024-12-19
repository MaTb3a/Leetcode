var maxChunksToSorted = function(arr) {
    if (arr[0] === 0) {
        arr[0] = 1;
    } else {
        arr[1] = Math.max(arr[0], arr[1]);
        arr[0] = 0;
    }
    
    for (let i = 1; i < arr.length; i++) {
        arr[i] = Math.max(arr[i], arr[i - 1]);
        if (arr[i] === i) {
            arr[0]++;
        }
    }
    
    return arr[0];
};
