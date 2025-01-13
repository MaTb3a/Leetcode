class Solution {
public:
    int minimumLength(string s) {
        int mask1 = 0,mask2 = 0;
        int removes = 0;
        for(char ch : s){
            if(!(mask1&(1<<(ch-'a'))))mask1|=(1<<(ch-'a'));
            else if(!(mask2&(1<<(ch-'a'))))mask2|=(1<<(ch-'a'));
            else
                removes+=2,mask1&=~(1<<(ch-'a'));
        }
        return s.size()-removes;

    }
};