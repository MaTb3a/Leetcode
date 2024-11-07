class Solution {
public:
    int mySqrt(int x) {
       
        int l = 0, r = x, md ,cur=-1;
        while(l<=r){
            md = l+r>>1; // (l+r)/2
            if(1LL * md*md <= x){
                cur = md;
                l = md+1;
            }
            else r = md-1;
        }
        return cur;
    }
};