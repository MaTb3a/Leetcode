class Solution {
public:
    string reverseParentheses(string s) {
            stack<int>stk;
            string ans = "";
            int n = s.size();
            vector<int>v(n);

            for(int i = 0 ; i < n ;i++){
                if(s[i]=='(')
                    stk.push(i);
                else if(s[i]==')'){
                    int j = stk.top();
                    stk.pop();
                    v[i] = j;
                    v[j] = i;
                }
            }

            int idx = 0, dir = 1;
            while(idx < n){
                if(s[idx] == '(' || s[idx] == ')'){
                    idx = v[idx];
                    dir = -dir;
                }
                else {
                    ans+=s[idx];
                }
                idx+=dir;
            }
            return ans;
    }
};