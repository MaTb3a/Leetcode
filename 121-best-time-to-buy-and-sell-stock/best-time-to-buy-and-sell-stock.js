/**
 * @param {number[]} prices
 * @return {number}
 */
const maxProfit = prices => prices.reduce(([min,profit],p) => [Math.min(min,p), Math.max(profit, p - Math.min(min,p))], [Number.MAX_SAFE_INTEGER,0])[1];
