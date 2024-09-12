class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bitset<26>vis;
        // int  -> vis
        for(char ch : allowed)vis[ch-'a']=true;
        int cnt = 0;
        for(string word : words){
            bool ok = true;
            for(char ch : word){
                if(!vis[ch-'a']){
                    ok = false;break;
                }
            }
            cnt+=ok;
        }
        return cnt;
    }
};