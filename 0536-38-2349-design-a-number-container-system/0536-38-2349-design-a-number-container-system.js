class NumberContainers {
    constructor() {
        this.indexToNumber = new Map();
        this.numberToIndices = new Map();
    }

    change(index, number) {
        if (this.indexToNumber.has(index)) {
            let oldNumber = this.indexToNumber.get(index);
            if (this.numberToIndices.has(oldNumber)) {
                let arr = this.numberToIndices.get(oldNumber);
                let idx = arr.indexOf(index);
                if (idx !== -1) arr.splice(idx, 1); 
                if (arr.length === 0) this.numberToIndices.delete(oldNumber);
            }
        }

        this.indexToNumber.set(index, number);
        if (!this.numberToIndices.has(number)) this.numberToIndices.set(number, []);
        
        let arr = this.numberToIndices.get(number);
        let pos = this.binaryInsert(arr, index);  
        arr.splice(pos, 0, index);
    }

    find(number) {
        return this.numberToIndices.has(number) && this.numberToIndices.get(number).length > 0
            ? this.numberToIndices.get(number)[0] // Smallest index
            : -1;
    }

    binaryInsert(arr, val) {
        let left = 0, right = arr.length;
        while (left < right) {
            let mid = Math.floor((left + right) / 2);
            if (arr[mid] < val) left = mid + 1;
            else right = mid;
        }
        return left;
    }
}
