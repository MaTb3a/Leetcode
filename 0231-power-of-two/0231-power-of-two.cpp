class Solution {
public:
    bool isPowerOfTwo(long long n) {
        return n>0 && (n & -n) == n;
    }
};