class Solution {
public:
    inline int solve(string &s,bool cur){
        int cnt = 0;
        for(auto t :s){
            if(t-'0'!=cur)cnt++;
            cur=!cur;
        }
        return cnt;
    }
    int minOperations(string s) {
        return min(solve(s,0),solve(s,1));
    }
};