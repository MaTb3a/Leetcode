class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size() -1;
        int cnt = 0;
        while( l < r){
            char c = s[l];
            int a = 0,b = 0 ;
            while(l < r && s[l]==c)l++,a++;
            while(l <= r && s[r]==c)r--,b++;
            if(a && b)cnt+=(a+b);
            else break;
        }
        return s.size()-cnt;
    }
};