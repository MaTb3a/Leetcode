class Solution {
public:
    inline bool ok(string &s){
        int i = 0 , j = s.size()-1;
        while( i < j && s[i]==s[j] )i++,j--;
        return i>=j;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto t : words)if(ok(t))return t;
        return "";
    }
};