class Solution {
public:
    struct Union{
        vector<int>parent;
        public:
            int component;
            Union(int n){
                component = n;
                parent = vector<int>(n+1);
                iota(parent.begin(),parent.end(),0);
            }
            int find(int u){
                if( u == parent[u])
                    return u;
                return parent[u] = find(parent[u]);
            }
            bool join(int u,int v){
                u = find(u);
                v = find(v);
                if(u == v)return 0;
                component--;
                parent[u] = v;
                return 1;
            }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Union alice(n),bob(n);
        int cnt = 0;
        for(auto edge : edges){
            if(edge[0] == 3){
                cnt+= (alice.join(edge[1],edge[2]) | bob.join(edge[1],edge[2]));
            }
        }
        for(auto edge : edges){
            if(edge[0] == 1)cnt+=alice.join(edge[1],edge[2]);
            if(edge[0] == 2)cnt+=bob.join(edge[1],edge[2]);
        }
        if(alice.component !=1 || bob.component != 1)
            return -1;
        return edges.size() - cnt;
    }
};