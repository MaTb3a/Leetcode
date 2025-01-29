class Solution {
public:
    int par[1001];
    int find(int u){
        if(u == par[u])return u;
        return par[u] = find(par[u]);
    }
    void join(int u,int v){
        u = find(u);
        v = find(v);
        if(u != v)
            par[u] = v;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        iota(par,par+1001,0);
        for(auto it : edges){
            if(find(it[0]) == find(it[1]))return it;
            join(it[0],it[1]);
        }
        return {};

    }
};