class MinHeap {
    constructor() {
        this.heap = [];
    }

    push(val) {
        this.heap.push(val);
        this._heapifyUp();
    }

    pop() {
        const top = this.heap[0];
        const end = this.heap.pop();
        if (this.heap.length > 0) {
            this.heap[0] = end;
            this._heapifyDown();
        }
        return top;
    }

    isEmpty() {
        return this.heap.length === 0;
    }

    _heapifyUp() {
        let index = this.heap.length - 1;
        const element = this.heap[index];

        while (index > 0) {
            const parentIndex = Math.floor((index - 1) / 2);
            const parent = this.heap[parentIndex];

            if (element[0] >= parent[0]) break;

            this.heap[index] = parent;
            index = parentIndex;
        }
        this.heap[index] = element;
    }

    _heapifyDown() {
        let index = 0;
        const length = this.heap.length;
        const element = this.heap[index];

        while (true) {
            let leftChildIndex = 2 * index + 1;
            let rightChildIndex = 2 * index + 2;
            let swapIndex = null;

            if (leftChildIndex < length) {
                if (this.heap[leftChildIndex][0] < element[0]) {
                    swapIndex = leftChildIndex;
                }
            }

            if (rightChildIndex < length) {
                if (
                    this.heap[rightChildIndex][0] <
                    (swapIndex === null ? element[0] : this.heap[swapIndex][0])
                ) {
                    swapIndex = rightChildIndex;
                }
            }

            if (swapIndex === null) break;

            this.heap[index] = this.heap[swapIndex];
            index = swapIndex;
        }

        this.heap[index] = element;
    }
}

var trapRainWater = function(heightMap) {
    const n = heightMap.length, m = heightMap[0].length;
    const visited = Array.from({ length: n }, () => Array(m).fill(false));
    const pq = new MinHeap();

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (i === 0 || j === 0 || i === n - 1 || j === m - 1) {
                pq.push([heightMap[i][j], i, j]);
                visited[i][j] = true;
            }
        }
    }

    let ans = 0, level = 0;
    const directions = [-1, 0, 1, 0, -1];

    while (!pq.isEmpty()) {
        const [height, x, y] = pq.pop();
        level = Math.max(level, height);
        for (let i = 0; i < 4; i++) {
            const nx = x + directions[i], ny = y + directions[i + 1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {
                visited[nx][ny] = true;
                ans += Math.max(0, level - heightMap[nx][ny]);
                pq.push([heightMap[nx][ny], nx, ny]);
            }
        }
    }

    return ans;
};
