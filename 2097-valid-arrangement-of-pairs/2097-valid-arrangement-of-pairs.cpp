class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<int>path;
    void Euler(int u){
        stack<int>stk;
        stk.push(u);
        while(stk.size()){
            int node = stk.top();
            if(adj[node].empty()){
                path.push_back(node);
                stk.pop();
            }
            else {
                int child = adj[node].back();
                adj[node].pop_back();
                stk.push(child);
            }
        }


    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,int>vis;
        for(auto it : pairs){
            vis[it[0]]++;
            vis[it[1]]--;
            adj[it[0]].push_back(it[1]);
        }
        int start = pairs[0][0];
        for(auto it : vis)
            if(it.second == 1)start = it.first;
        Euler(start);
        vector<vector<int>>ans;
        // 1 5 4 9 11
        for(int i = path.size()-2 ; i >=0 ;i--){
            ans.push_back({path[i+1],path[i]});
        }
        return ans;

    }
};