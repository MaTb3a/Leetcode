class Solution {
public:
    int minDeletions(string s) {
        int vis[26];
        memset(vis,0,sizeof vis);
        for(auto t : s)
            vis[t-'a']++;
        map<int,int>mp;
        int ans=0;
        for(int i = 0;i<26;i++){
            int x=vis[i];
            
            while(x && mp.find(x)!=mp.end()){
                x--;
                ans++;
            }
            mp[x]++;
        }
        return ans;
    }
};