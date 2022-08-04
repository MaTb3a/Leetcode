class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm = p * q / __gcd(p, q);
        return ((lcm / p) % 2 == 0) ? 0 : ((lcm / q) % 2 == 0) ? 2 : 1;
    }
};