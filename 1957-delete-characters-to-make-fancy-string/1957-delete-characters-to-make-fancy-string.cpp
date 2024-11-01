class Solution {
public:
    string makeFancyString(string s) {
        int j = 2;
        for(int i = 2 ; i < s.size();i++){
            if( s[i] ==s[j-1] && s[i] == s[j-2])continue;
            s[j++] = s[i]; 
        }
        return s.substr(0,j);
    }
};