class Solution {
public:
    int kmp(string &s){
        int len = 0;
        vector<int>f(s.size());
        for(int i = 1 ; i < s.size();i++){
            while(len && s[i] != s[len])
                len = f[len-1];
            if(s[i] == s[len])len++;
            f[i]=len;
        }
        return f.back();
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        string newS = s + "$" + rev;
        int idx = kmp(newS);
        int len = s.size() - idx;

        return rev.substr(0,len)+s;
    }
};