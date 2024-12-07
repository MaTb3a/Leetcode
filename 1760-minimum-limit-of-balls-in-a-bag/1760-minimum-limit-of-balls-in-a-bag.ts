var minimumSize = function(nums, maxOperations) {
    const canDivide = (mid) => {
        let operations = 0;
        for (const bag of nums) {
            operations += Math.floor((bag - 1) / mid);
        }
        return operations <= maxOperations;
    };

    let left = 1, right = Math.max(...nums), result = -1;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        if (canDivide(mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
};
