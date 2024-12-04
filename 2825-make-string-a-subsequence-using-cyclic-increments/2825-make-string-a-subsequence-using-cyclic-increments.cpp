class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
       
        int j = 0;
        for(char c : str1)
            j+=(c == str2[j] || c-str2[j] == 25 | c-str2[j]==-1 );
        return j == str2.size();


    }
};