class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int> &vis,vector<int> &res,bool &cycle){
        vis[node] = 1;
        for(int child : adj[node]){
            if(!vis[child]){
                dfs(child,adj,vis,res,cycle);
                if(cycle)return;
            }
            else if(vis[child] == 1){
                cycle  = true;
                return;
            }
        }
        vis[node] = 2;
        res.push_back(node);
    }
    vector<int> topo(vector<vector<int>>&data, int k){
        vector<vector<int>>adj(k+1);
        for(auto it : data){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> res , vis(k+1);
        bool cycle = false;
        // 0 not vist 1 visiting  2 visited 
        for(int i = 1 ; i <= k ; i++){
            if(!vis[i])
                dfs(i,adj,vis,res,cycle);
            if(cycle)
                return {};
        }
        reverse(res.begin(),res.end());
        return res;

    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>r = topo(rowConditions,k);
        vector<int>c = topo(colConditions,k);
        if(r.empty() || c.empty())
            return {};
         vector<vector<int>>matrix(k,vector<int>(k));
         for(int i = 0 ; i < k ; i++)
            for(int j = 0 ; j < k ; j++)
                if(r[i] == c[j])
                    matrix[i][j] = r[i];
          
        return matrix;
    }
};