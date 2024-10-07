class Solution {
public:
    int minLength(string s) {
        int lst = 0;
        for(int i = 0 ; i < s.size();i++){
            if(s[i] == 'B' && lst && s[lst-1] == 'A')lst--;
            else if(s[i] == 'D' && lst &&  s[lst-1] == 'C')lst--;
            else s[lst] = s[i],lst++;
        }
        return lst;
    }
};