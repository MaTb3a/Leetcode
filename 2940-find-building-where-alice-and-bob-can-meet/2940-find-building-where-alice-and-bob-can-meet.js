class MinHeap {
    constructor() {
        this.heap = [];
    }

    push(element) {
        this.heap.push(element);
        this._heapifyUp(this.heap.length - 1);
    }

    pop() {
        if (this.size() === 1) return this.heap.pop();
        const top = this.heap[0];
        this.heap[0] = this.heap.pop();
        this._heapifyDown(0);
        return top;
    }

    peek() {
        return this.heap[0];
    }

    size() {
        return this.heap.length;
    }

    _heapifyUp(index) {
        while (index > 0) {
            const parent = Math.floor((index - 1) / 2);
            if (this.heap[parent][0] <= this.heap[index][0]) break;
            [this.heap[parent], this.heap[index]] = [this.heap[index], this.heap[parent]];
            index = parent;
        }
    }

    _heapifyDown(index) {
        const size = this.heap.length;
        while (true) {
            let smallest = index;
            const left = 2 * index + 1;
            const right = 2 * index + 2;

            if (left < size && this.heap[left][0] < this.heap[smallest][0]) smallest = left;
            if (right < size && this.heap[right][0] < this.heap[smallest][0]) smallest = right;

            if (smallest === index) break;
            [this.heap[smallest], this.heap[index]] = [this.heap[index], this.heap[smallest]];
            index = smallest;
        }
    }
}

var leftmostBuildingQueries = function(heights, queries) {
    const n = heights.length;
    const m = queries.length;
    const v = Array.from({ length: n }, () => []);
    const ans = Array(m).fill(-1);

    for (let i = 0; i < m; i++) {
        let [x, y] = queries[i];
        if (x > y) [x, y] = [y, x];
        if (x === y || heights[x] < heights[y]) {
            ans[i] = y;
        } else {
            v[y].push([Math.max(heights[x], heights[y]), i]);
        }
    }

    const pq = new MinHeap();
    for (let i = 0; i < n; i++) {
        for (const [h, idx] of v[i]) {
            pq.push([h, idx]);
        }
        while (pq.size() && pq.peek()[0] < heights[i]) {
            const [, idx] = pq.pop();
            ans[idx] = i;
        }
    }

    return ans;
};
