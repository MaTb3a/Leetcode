class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int>stk;
        for(int i = n-1 ; i >= 0 ; i--){
            while(stk.size() && stk.top() > prices[i])stk.pop();
            int tmp = prices[i];
            if(stk.size())prices[i]-=stk.top();
            stk.push(tmp);
        }
        return prices;
    }
};