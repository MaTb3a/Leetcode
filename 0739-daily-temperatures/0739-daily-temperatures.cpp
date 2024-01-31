class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>stk;  
        vector<int>v;
        for(int i = temperatures.size() -1 ; i >= 0 ; i--){
            while(stk.size() && temperatures[stk.top()] <= temperatures[i])stk.pop();
            if(stk.size()) v.push_back(stk.top() - i);
            else v.push_back(0);
            stk.push(i);  
        }
        reverse(v.begin(),v.end());
        
        return v;
    }
};