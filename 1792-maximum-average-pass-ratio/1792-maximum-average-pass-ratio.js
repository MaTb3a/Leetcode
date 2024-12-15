class MaxHeap {
    constructor() {
        this.heap = [];
    }

    // Add an element to the heap
    push(element) {
        this.heap.push(element);
        this._heapifyUp(this.heap.length - 1);
    }

    // Remove and return the max element
    pop() {
        if (this.heap.length === 1) return this.heap.pop();
        const max = this.heap[0];
        this.heap[0] = this.heap.pop();
        this._heapifyDown(0);
        return max;
    }

    // Check if the heap is empty
    isEmpty() {
        return this.heap.length === 0;
    }

    // Get the size of the heap
    size() {
        return this.heap.length;
    }

    // Restore heap property after adding a new element
    _heapifyUp(index) {
        while (index > 0) {
            const parent = Math.floor((index - 1) / 2);
            if (this.heap[parent].gain >= this.heap[index].gain) break;
            [this.heap[parent], this.heap[index]] = [this.heap[index], this.heap[parent]];
            index = parent;
        }
    }

    // Restore heap property after removing the max element
    _heapifyDown(index) {
        const size = this.heap.length;
        while (true) {
            let largest = index;
            const left = 2 * index + 1;
            const right = 2 * index + 2;

            if (left < size && this.heap[left].gain > this.heap[largest].gain) {
                largest = left;
            }
            if (right < size && this.heap[right].gain > this.heap[largest].gain) {
                largest = right;
            }
            if (largest === index) break;

            [this.heap[largest], this.heap[index]] = [this.heap[index], this.heap[largest]];
            index = largest;
        }
    }
}

var maxAverageRatio = function(classes, extraStudents) {
    const calcGain = (x, y) => (x + 1) / (y + 1) - x / y;

    // Initialize max heap with initial gains
    const pq = new MaxHeap();
    for (const [x, y] of classes) {
        pq.push({ x, y, gain: calcGain(x, y) });
    }

    // Distribute extra students
    while (extraStudents--) {
        const { x, y } = pq.pop();
        pq.push({ x: x + 1, y: y + 1, gain: calcGain(x + 1, y + 1) });
    }

    // Calculate the final average ratio
    let totalRatio = 0;
    while (!pq.isEmpty()) {
        const { x, y } = pq.pop();
        totalRatio += x / y;
    }

    return totalRatio / classes.length;
};
