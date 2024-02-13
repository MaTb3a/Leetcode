class Solution {
public:
    // inline bool ok(string &s){
    //     int i = 0 , j = s.size()-1;
    //     while(s[i++]!=s[j--]){
    //         if(i>=j)return 1;
    //         return 0;
    //     }
    //     return 1;
    // }
    string firstPalindrome(vector<string>& words) {
        
        for(auto t : words){
            string t2 = t;
            reverse(t2.begin(),t2.end());
            if(t == t2)return t;
        }
        return "";
    }
};