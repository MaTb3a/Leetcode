class Solution {
public:
    
    string frequencySort(string s) {
        int vis[256]={0};
        for(auto t : s)vis[t]++;
        sort(s.begin(),s.end(),[&](char a, char b){
            return vis[a]>vis[b] || (vis[a]== vis[b] && a > b);
        });
        return s;
        
    }
};