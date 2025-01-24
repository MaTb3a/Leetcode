class Solution {
public:
    bool dfs(int u,vector<vector<int>>& graph,vector<int>&state){
        if(state[u])return state[u] == 1;
        state[u] = 2;
        for(int child : graph[u])
            if(dfs(child,graph,state) == 0)
                return false;
        return state[u] = 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>state(n),ans;
        for(int i = 0 ; i < n;i++)
            if(dfs(i,graph,state))
                ans.push_back(i);
        
         return ans;
        
    }
};