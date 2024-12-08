var maxTwoEvents = function(events) {
    // Sort events by their end time
    events.sort((a, b) => a[1] - b[1]);

    const endTimes = [];
    const maxValues = [];
    let result = 0;

    for (const [start, end, value] of events) {
        // Find the latest event that ends before the current event starts
        let idx = binarySearch(endTimes, start) - 1;

        // Update the result with the best combination of the current and prior event
        if (idx >= 0) {
            result = Math.max(result, value + maxValues[idx]);
        } else {
            result = Math.max(result, value);
        }

        // Update maxValues and endTimes
        if (maxValues.length === 0) {
            maxValues.push(value);
        } else {
            maxValues.push(Math.max(maxValues[maxValues.length - 1], value));
        }
        endTimes.push(end);
    }

    return result;

    // Binary search to find the first element greater than or equal to the target
    function binarySearch(arr, target) {
        let low = 0, high = arr.length;
        while (low < high) {
            const mid = Math.floor((low + high) / 2);
            if (arr[mid] >= target) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
