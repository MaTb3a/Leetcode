class Solution {
public:
    int bitwiseComplement(int n) {
        bitset<32>bit(1);
        for(int i = 0 ; n;i++){
            if(n&1)bit[i] = 0;
            else bit[i] =1;
            n>>=1;
        }
        return bit.to_ulong();
    }
};