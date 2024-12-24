class Solution {
public:
    int d,lst;
    void dfs(int node,int par,vector<vector<int>>&adj,int dep){
        if(dep > d){
            d = dep;
            lst = node;
        }
        for(int child : adj[node]){
            if(par == child)continue;
            dfs(child,node,adj,dep+1);
        }
    }
    int getDiamiter(vector<vector<int>>& edges){
        int n = edges.size()+1;
        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        lst = d = 0;
        dfs(0,-1,adj,0);
        d = 0;
        dfs(lst,-1,adj,0);
        return d;
    }
   
    pair<int,int> BFS(int src,vector<vector<int>>&adj){
        int n = adj.size()+1;
        queue<int>q;
        q.push(src);
        vector<bool>vis(n);
        int lst = 0,len = 0;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                 int node = q.front();q.pop();
                 vis[node] = 1;
                 lst = node;
                 for(int child : adj[node]){
                    if(!vis[child])q.push(child);
                 }
            }
            len++;
        }
        return {lst,len};
    }
     int getDiamiter2(vector<vector<int>>& edges){
        int n = edges.size()+1;
        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        pair<int,int>p = BFS(0,adj);
        return BFS(p.first,adj).second-1;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = getDiamiter2(edges1);
        int d2 = getDiamiter2(edges2);
        int d1d2 = ceil(d1/2.0) + ceil(d2/2.0)+1;
        return  max({d1,d2,d1d2});
       
    }
};