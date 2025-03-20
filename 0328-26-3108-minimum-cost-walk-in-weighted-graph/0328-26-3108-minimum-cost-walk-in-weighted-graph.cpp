class Solution {
public:
    vector<int>parent,costs;
    int find(int u){
        if(parent[u] == u)return u;
        return parent[u] = find(parent[u]);
    }
    void join (int u,int v,int w){
        u = find(u);
        v = find(v);
        costs[u] = costs[v] =  costs[u] & costs[v]  & w;
        parent[v] = u;
    }
    int calc(int u,int v){
        u = find(u); v = find(v);
        if(u != v)return -1;
        return costs[u];
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent = costs  = vector<int>(n,-1);
        iota(parent.begin(),parent.end(),0); 

        for(auto it : edges) join(it[0],it[1],it[2]);
        
        vector<int>v;
        v.reserve(query.size());
        for(auto it : query)v.push_back(calc(it[0],it[1]));
        return v;



    }
};