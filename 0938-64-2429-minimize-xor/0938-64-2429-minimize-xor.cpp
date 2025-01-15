class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int diff = __builtin_popcount(num2) - __builtin_popcount(num1);
        for(int i = 0 ; i< 32 && diff ;i++){
            if(diff > 0 && !(num1 & (1<<i))){
                diff--;
                num1^=(1<<i);
            }
            if(diff < 0 && (num1 & (1<<i))){
                diff++;
                num1^=(1<<i);
                
            }
        }
        return num1;
        
    }
};