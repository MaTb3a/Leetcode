class Solution {
public:
    int maxDepth(string s) {
        int open = 0,mx = 0;
        for(auto t : s){
            if(t=='(')open++;
            if(t==')')open--;
            mx=max(mx,open);
        }
        return mx;
    }
};