class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size())return false;
        int frq = 0; 
        for(char ch : s)
            frq ^= (1<<(ch-'a'));      
        return __builtin_popcount(frq) <= k;
    }
};