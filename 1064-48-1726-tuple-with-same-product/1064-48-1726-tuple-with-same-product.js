var tupleSameProduct = function(nums) {
    let productCount = new Map();
    let count = 0;

    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            let product = nums[i] * nums[j];
            count += (productCount.get(product) || 0) * 8;
            productCount.set(product, (productCount.get(product) || 0) + 1);
        }
    }

    return count;
};
