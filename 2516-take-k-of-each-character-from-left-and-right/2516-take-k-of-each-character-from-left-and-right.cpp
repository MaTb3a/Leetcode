class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int>vis(3);
        for(auto it : s)
            vis[it-'a']++;
        if(*min_element(vis.begin(),vis.end())<k)return -1;
        // vis[0] vis[1] vis[2]
        int l = 0,r = 0,ans = 0;
        while(r < n){
            vis[s[r]-'a']--;
            while(*min_element(vis.begin(),vis.end())<k){
                vis[s[l]-'a']++;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return n - ans;
    }
};