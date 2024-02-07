class Solution {
public:
    
    
    string frequencySort(string s) {
        unordered_map<char,int>vis;
        for(auto t : s)vis[t]++;
        sort(s.begin(),s.end(),[&](char a ,char b){
            if (vis[a] > vis[b])return true;
            if(vis[a] == vis[b])return a < b;
            return false;
        });
        return s;
        
    }
};