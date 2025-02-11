class Solution {
public:
    short lps[1001];
    void kmp(string part){
        int j = 0;
        for(int i = 1 ; i < part.size();i++){
            while(j && part[i] != part[j]) j = lps[j-1];
            if(part[i] == part[j])lps[i] = ++j;
        }
    }
    string removeOccurrences(string s, string part) {
        int sz = part.size();
        kmp(part);
        vector<short>stk;
        string ans;
        int j = 0;
        for(char ch : s){
            ans.push_back(ch);
            stk.push_back(j);
            while(j && ch != part[j]) j = lps[j-1];
            if(ch == part[j]) ++j;
            stk.back() = j;
            if( j == sz){
                ans.resize(ans.size()-sz);
                stk.resize(stk.size()-sz);
                j = stk.size() ? stk.back() : 0 ;
            }
            
        }
        return ans;


    }
};