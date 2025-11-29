class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>stk;
        stk.push(-1);
        int n = arr.size();
        vector<int>l(n),r(n);

        for(int i = 0 ; i < n;i++){
            while(stk.size() > 1 && arr[i] < arr[stk.top()])stk.pop();
            l[i] = stk.top();
            stk.push(i);
        }

        stk = stack<int>();
        stk.push(n);
        
        for(int i = n -1 ;i >= 0 ; i--){
            while(stk.size() > 1 && arr[i] <= arr[stk.top()])stk.pop();
            r[i] = stk.top();
            stk.push(i);
        }
        long long ans = 0;
        const int mod = 1e9+7;
        for(int i = 0 ; i < n;i++){
            ans += (1LL*(i-l[i]) *1LL*(r[i]-i)*arr[i]);
            ans%=mod;
        }
        return ans;
    }
};