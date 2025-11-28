class Solution {
public:
    int solve(int u,vector<vector<int>>& adj, vector<int>& values, int k,vector<bool>&vis){
        if(vis[u])return 0;
        vis[u] = true;
        int ret = 0,l,r;
        for(int ch : adj[u]){
            if(!vis[ch]){
                ret+=solve(ch,adj,values,k,vis);
                values[u]=(values[u] + values[ch])%k;
            }
        }
        ret+=values[u]%k==0;
        return ret;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        int root = -1;
        for(auto it : edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[v]++;
        }
        vector<bool>vis(n);
        for(int i = 0 ; i < n ;i++)
            if(!indegree[i])root = i;
        return solve(root,adj,values,k,vis);
    }
};