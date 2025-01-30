class Solution {
public:
    bool dfs(int node,bool c,vector<vector<int>>&adj,vector<int>&color,vector<int>&v){
        color[node] = c;
        v.push_back(node);
        for(int child : adj[node]){
            if(color[child] == c)return false;
            if(color[child] == -1 && !dfs(child,!c,adj,color,v))return false;
        }
        return true;
    }
    int bfs(vector<int>&v,vector<vector<int>>&adj,int n){
        int mx = 0;
        for(int st : v){
            queue<int>q{{st}};
            vector<int>dist(n+1,-1);
            dist[st] = 0;
            while(q.size()){
                int node = q.front();q.pop();
                 for(int child : adj[node]){
                    if(dist[child]!=-1)continue;
                    dist[child] = dist[node]+1;
                    mx=max(mx,dist[child]);
                    q.push(child);
                 }
            }
        }
        return mx+1;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1);
        vector<int>color(n+1,-1);
        for(auto it : edges)
            adj[it[0]].push_back(it[1]),adj[it[1]].push_back(it[0]);
        int ans = 0;
        for(int i = 1 ; i <= n ;i++){
            if(color[i]!=-1)continue;
            vector<int>v;
            if(!dfs(i,0,adj,color,v))return -1;
            ans+=bfs(v,adj,n);
        }
        return ans;
        
    }
};