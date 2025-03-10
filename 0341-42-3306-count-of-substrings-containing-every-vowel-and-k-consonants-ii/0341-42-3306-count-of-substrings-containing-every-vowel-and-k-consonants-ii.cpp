class Solution {
public:
    int mp[26];
    inline bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch =='i' || ch=='u' || ch == 'o';
    }
    inline bool check(){
        return mp['a'-'a'] &&  mp['e'-'a'] && mp['i'-'a'] && mp['u'-'a'] && mp['o'-'a'];
    }
    long long solve(string s,int k){
        long long ans = 0;
        int n = s.size(), cons = 0, l = 0;
        memset(mp,0,sizeof mp);
        for(int r = 0 ; r < n ;r++){
            isVowel(s[r])? mp[s[r]-'a']++ : cons++;
            while(check() && cons >= k){
                ans+=n-r;
                isVowel(s[l])? mp[s[l]-'a']-- : cons--;
                l++;

            }
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return solve(word,k) - solve(word,k+1);
    }
};