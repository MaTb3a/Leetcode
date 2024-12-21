class Solution {
public:
    vector<vector<int>> adj;
    int ans = 0;
    vector<bool>vis;
    int dfs(int node,vector<int>& values, int k){
        vis[node] = true;
        long long sum = values[node];
        for(int child : adj[node]){
            if(vis[child])continue;
            sum+=dfs(child,values,k);
            sum%=k;
        }
        if(sum%k==0)ans++;
        return sum;
    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n==1)return 1;
        adj.resize(n);
        vis.resize(n);
        vector<int>degree(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }
        queue<int>q;
        for(int i = 0 ; i < n;i++)if(degree[i]==1)q.push(i);
        while(q.size()){
            int node = q.front();q.pop();
            degree[node]--;
            if(values[node]%k==0)ans++;

            for(int child : adj[node]){
                degree[child]--;
                values[child]+=values[node];
                values[child]%=k;
                if(degree[child]==1)q.push(child);
            }
        }

        return ans;

    }
};