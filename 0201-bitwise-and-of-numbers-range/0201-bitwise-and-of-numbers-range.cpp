class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
                if(!left||!right)return 0;

        int ans =right;
        for(long long i = left ; i < right; i += (i - (i &(i-1)))){
            ans&=i;
        }
        return ans;
    }
};

//11 =>1011
//14 =>1110
//----------
//     