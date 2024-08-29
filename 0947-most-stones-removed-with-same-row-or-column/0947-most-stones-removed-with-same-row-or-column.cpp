class Solution {
public:
    vector<vector<int>>g;
    vector<bool>vis;
    int cnt = 0;
    void dfs(int u){
        vis[u] = 1;
        for(auto child : g[u])
            if(!vis[child])dfs(child);
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        g = vector<vector<int>>(n);
        vis = vector<bool>(n);
        for(int i = 0 ; i < n ;i++)
            for(int j = i+1 ; j < n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    g[i].push_back(j),g[j].push_back(i);
            }
        for(int i = 0 ; i < n ;i++)
            if(!vis[i])cnt++,dfs(i);
        return n - cnt;
        
    }
};