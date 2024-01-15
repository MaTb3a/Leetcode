class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>vis;
        for(auto t : matches){
            if(vis.find(t[0])==vis.end())vis[t[0]]=0;
            vis[t[1]]--;
        }
        vector<vector<int>>v(2);
        for(auto t : vis){
            if(!t.second)v[0].push_back(t.first);
            if(t.second == -1) v[1].push_back(t.first);
        }
        return v;
    }
};