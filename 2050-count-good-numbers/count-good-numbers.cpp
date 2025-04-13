class Solution {
public:
    const int mod = 1e9+7;
    long long fast_power(int base, long long p){ 
        if(!p)return 1;
        long long half = fast_power(base,p/2);
        return ((half * half)%mod * (p & 1  ? base : 1 ))%mod;
    }
    int countGoodNumbers(long long n) {
        return (fast_power(5,(n+1)/2) * fast_power(4,n/2))%mod;
    }
};