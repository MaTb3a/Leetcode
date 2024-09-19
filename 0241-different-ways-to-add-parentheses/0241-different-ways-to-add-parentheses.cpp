class Solution {
public:
    vector<int> memo[21][21];
    vector<int> solve(int i,int j,string &s){
        if(i == j)return {s[i]-'0'};
        if(i+1 == j) return {(s[i]-'0') * 10 + s[j]-'0'};
        if(memo[i][j].size())return memo[i][j];
        vector<int> v;
        for(int k = i+1; k < j;k++){
            char op  = s[k]; 
            if(op == '+' || op == '-' || op == '*'){
                vector<int> left = solve(i,k-1,s);
                vector<int> right = solve(k+1,j,s);
                for(int l : left)
                    for(int r : right)
                        if(op=='+') v.push_back(l+r);
                        else if(op == '-')v.push_back(l-r);
                        else v.push_back(l*r);
            }
        }
        return memo[i][j] = v;
    }
    vector<int> diffWaysToCompute(string expression) {
        // vector<int> v;
        // for(int i = 0 ; i < expression.size();i++){
        //     char op  = expression[i]; 
        //     if(op == '+' || op == '-' || op == '*'){
        //         vector<int> left = diffWaysToCompute(expression.substr(0,i));
        //         vector<int> right = diffWaysToCompute(expression.substr(i+1));
        //         for(int l : left)
        //             for(int r : right)
        //                 if(op=='+') v.push_back(l+r);
        //                 else if(op == '-')v.push_back(l-r);
        //                 else v.push_back(l*r);
        //     }
        // }
        // if(v.empty())v.push_back(stoi(expression));
        // return v;
        return solve(0,expression.size()-1,expression);
    }
};