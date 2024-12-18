var finalPrices = function(prices) {
    const n = prices.length;
    const stack = [];
    for (let i = n - 1; i >= 0; i--) {
        while (stack.length && stack[stack.length - 1] > prices[i]) {
            stack.pop();
        }
        const tmp = prices[i];
        if (stack.length) {
            prices[i] -= stack[stack.length - 1];
        }
        stack.push(tmp);
    }
    return prices;
};
