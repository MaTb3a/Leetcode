class Solution {
public:
    vector<int>BobT,parent;
    void BobDfs(int n,int p,vector<vector<int>>&adj){
        parent[n] = p;
        for(int ch : adj[n]){
            if(ch == p)continue;
            BobDfs(ch,n,adj);
        }
    }
     int AliceDfs(int n,int p,vector<vector<int>>&adj,int AliceT,vector<int>& amount){
        int AliceM = 0;
        if(AliceT < BobT[n])AliceM = amount[n];
        if(AliceT ==  BobT[n])AliceM = amount[n]/2;
        if(adj[n].size() == 1 && n != 0)return AliceM;
        int mx = -1e9;
        for(int ch : adj[n]){
            if(ch == p)continue;
            mx=max(mx, AliceDfs(ch,n,adj,AliceT+1,amount));
        }
        return mx + AliceM;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        BobT = parent = vector<int>(n,1e9);
        BobDfs(0,-1,adj);
        int time = 0;
        for(int i = bob ; i !=-1 ; i = parent[i])
            BobT[i] = time++;
        return AliceDfs(0,-1,adj,0,amount);


    }
};