class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>a(26),b(26);
        for(int i = 0 ; i < s.size();i++){
            a[s[i]-'a']++;
            b[t[i]-'a']++;
        }
        int cnt = 0;
        for(int i = 0;i<26;i++){
            cnt+=abs(a[i]-b[i]);
        }
        return cnt/2;
        
    }
};