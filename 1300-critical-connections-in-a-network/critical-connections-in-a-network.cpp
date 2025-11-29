class Solution {
public:
    vector<int>time,low;
    vector<vector<int>>ans;
    int T;
    void dfs(int u,int par,vector<vector<int>>& adj){
        time[u] = low[u] = ++T;
        for(int ch : adj[u]){
            if(time[ch]== -1){
                dfs(ch,u,adj);
                low[u] = min(low[u],low[ch]);
                if(low[ch] > time[u])
                    ans.push_back({ch,u});
            }
            else if(ch != par)
                low[u] = min(low[u],time[ch]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        T = 0;
        time = low = vector<int>(n,-1);

        dfs(0,-1,adj);
        return ans;
    }
};