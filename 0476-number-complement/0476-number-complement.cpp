class Solution {
public:
    int findComplement(int num) {
        unsigned int mx = (1<<((int)log2(num)));
        mx = (mx<<1)-1; 
        return mx ^ num;
    }
};