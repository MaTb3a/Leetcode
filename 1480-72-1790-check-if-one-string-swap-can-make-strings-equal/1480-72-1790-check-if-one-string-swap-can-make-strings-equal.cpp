class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int idx = -1;
        for(int i = 0 ; i < s1.size();i++){
            if(s1[i]==s2[i])continue;
            if(idx == -1)idx= i;
            else if(idx != -2){
                swap(s1[idx],s1[i]);
                if(s1[idx] != s2[idx] || s1[i] != s2[i])return false;
                idx = -2;
            }
            else return false;
        }
        return idx < 0;
    }
};