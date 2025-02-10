class Solution {
public:
    string clearDigits(string s) {
        int j = 0;
        for(int i = 0 ; i < s.size();i++)
            (isdigit(s[i]) && (j > 0)) ? --j :  s[j++] = s[i];
        s.resize(j);
        return s;
    }
};