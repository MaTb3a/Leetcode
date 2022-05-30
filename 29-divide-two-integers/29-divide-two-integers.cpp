class Solution {
public:
    int divide(long long dividend, long long divisor) {
        
        int sign = (((dividend<0) ^ (divisor<0)) ? -1 : 1);
        if(dividend == INT_MIN && divisor == -1)return INT_MAX;
        dividend = abs(dividend);
        divisor = abs(divisor);
        long long q = 0;
        for(int i=31;i>=0 ;i--){
            if((dividend >> i)   >= divisor){
                dividend -= (divisor<<i);
                q +=(1<<i);
            }
        }
        
        return q*sign;
    }
};