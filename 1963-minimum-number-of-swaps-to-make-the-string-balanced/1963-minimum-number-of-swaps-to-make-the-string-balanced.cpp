class Solution {
public:
    int minSwaps(string s) {
      
        int stk = 0;
        int cnt = 0;
        for(auto &it : s){
            if(it == '[')stk++;
            else { 
                if(stk)stk--;
                else cnt++;
            }
        }
        return (cnt+1)/2;
    }
};