class Solution {
public:
    int RomanToInt(char c){
        if (c == 'I')return             1;
        if (c == 'V')return             5;
        if (c == 'X')return             10;
        if (c == 'L')return             50;
        if (c == 'C')return             100;
        if (c == 'D')return             500;
        if (c == 'M')return             1000;
        return 0;
    }

    int romanToInt(string s) {
        int ans = 0, n = s.size();
        for(int i = 0 ; i < n;i++){
            int cur = RomanToInt(s[i]);
            int nxt = (i+1 < n ? RomanToInt(s[i+1]) : 0);
            if(cur < nxt)ans-=cur;
            else ans+=cur;
        }
        return ans;
    }
};