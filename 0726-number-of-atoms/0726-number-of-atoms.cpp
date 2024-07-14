class Solution {
public:
    string countOfAtoms(string formula) {
         
            stack<map<string,int>>stk;

            stk.push(map<string,int>());
            int n = formula.size();
            int idx = 0 ;
            while(idx < n){
                if(formula[idx] == '(')
                    stk.push(map<string,int>()),idx++;
                else if(formula[idx] == ')') {
                    int num = 0;idx++;
                    while(idx < n && isdigit(formula[idx]))
                        num = num * 10 + (formula[idx++]-'0');
                    auto curMap = stk.top();
                    stk.pop();
                    if(!num)num=1;
                    for(auto it : curMap){
                        stk.top()[it.first] += it.second * num;
                    }   
                }
                else {
                    string atom = "";
                    atom+=formula[idx++];
                    while(idx < n && islower(formula[idx]))
                        atom+=formula[idx++];
                    int num = 0;
                    while(idx < n && isdigit(formula[idx]))
                        num = num * 10 + (formula[idx++]-'0');
                    if(!num)num=1;
                    stk.top()[atom] += num;
                }
            }
            string ans = "";
            for(auto it : stk.top()){
                ans+=it.first + (it.second > 1 ? to_string(it.second) : "");
            }
            return ans;
    }
};