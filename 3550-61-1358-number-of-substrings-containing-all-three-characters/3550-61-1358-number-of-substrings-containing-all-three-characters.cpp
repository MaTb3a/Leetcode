class Solution {
public:
    int numberOfSubstrings(string s) {
        int vis[3]={-1,-1,-1},cnt=0;
        for(int i = 0 ; i < s.size();i++){
            vis[s[i]-'a'] = i; 
            cnt+=min({vis[0],vis[1],vis[2]})+1; 
        }
        return cnt;
    }
};