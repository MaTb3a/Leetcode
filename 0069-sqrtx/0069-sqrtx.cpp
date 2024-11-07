class Solution {
public:
    int mySqrt(int x) {
        
        int i = 2;
        for(   ;1LL* i*i <= x;i++)
            if(i*i >= x)return i;
        return x  < 2 ? x : i-1;
    }
};