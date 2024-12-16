class MinHeap {
    constructor() {
        this.heap = [];
    }

    push([value, index]) {
        this.heap.push([value, index]);
        this.heap.sort((a, b) => a[0] - b[0] || a[1] - b[1]); 
    }

    pop() {
        return this.heap.shift(); 
    }

    size() {
        return this.heap.length;
    }
}

var getFinalState = function(nums, k, multiplier) {
    const heap = new MinHeap();

    nums.forEach((num, idx) => heap.push([num, idx]));

    while (k--) {
        const [value, idx] = heap.pop();
        nums[idx] *= multiplier;
        heap.push([nums[idx], idx]);
    }

    return nums;
};
