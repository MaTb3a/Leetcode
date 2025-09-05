class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int k = 1;
        while (true) {
            long long x = num1 - 1LL*(num2) * k;
            if (x < k) return -1;
            if (k >= __builtin_popcountll(x)) return k;
            k++;
        }
    }
};