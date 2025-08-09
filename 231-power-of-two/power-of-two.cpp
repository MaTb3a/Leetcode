class Solution {
public:
    bool isPowerOfTwo(long long n) {
        return n && !(n&(n-1));
    }
};