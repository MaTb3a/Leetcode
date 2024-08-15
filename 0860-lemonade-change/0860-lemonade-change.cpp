class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int fives = 0, tens = 0;
        for(auto it : bills){
            if(it==5)fives++;
            else if(it==10){
                if(fives)fives--,tens++;
                else return false;
            }
            else {
                if(fives && tens)fives--,tens--;// 5 10
                else if(fives>=3)fives-=3; // 5 5 5
                else return false;
            }
        }
        return true;
    }
};