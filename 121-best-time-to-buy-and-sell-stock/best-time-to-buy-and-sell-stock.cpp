class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = 0;
        
        for (int p : prices)
            minPrice = min(minPrice, p),
            maxProfit = max(maxProfit, p - minPrice);
        return maxProfit;
    }
};