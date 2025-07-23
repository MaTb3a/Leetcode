class Solution {
public:
    int solve(string& s, char x, char y, int val) {
        string stk = "";
        int ans = 0;
        for (char ch : s) {
            if (stk.size() && stk.back() == x && ch == y) {
                stk.pop_back();
                ans += val;
            } else
                stk.push_back(ch);
        }
        s = stk;
        return ans;
    }

    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if (x >= y){
            ans = solve(s, 'a', 'b', x);
            return ans + solve(s, 'b', 'a', y);
        }
        else {
            ans = solve(s,'b','a',y);
            return ans + solve(s,'a','b',x);
        }
        return -1;
      
    }

};