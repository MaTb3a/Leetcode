class Solution {
public:
    vector<bool>vis;
    vector<vector<int>>adj;
    int sz;
    inline int dfs(int u){
        vis[u]=true;
        int ret = 1;
        sz &=adj[u].size();
        for(int ch : adj[u]){
            if(!vis[ch])
                ret+=dfs(ch);
        }
        return ret;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
          vis =  vector<bool>(n);
          adj = vector<vector<int>>(n);
          for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
          }
        
         int cnt = 0;
          for(int i = 0 ;i < n;i++){
            if(vis[i])continue;
            sz = adj[i].size();
            cnt+= (dfs(i) == sz + 1);
          }
          return cnt;
    }
};