class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low ; i <= high;i++){
            if(i > 9 && i < 100 && i%10 == i/10)cnt++; 
            else if(i>999 && i/1000 + i/100 % 10 ==   (i%100) / 10 + i%10)cnt++; 
        }
        return cnt;
    }
};