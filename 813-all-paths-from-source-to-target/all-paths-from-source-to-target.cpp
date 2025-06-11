class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    int n;
    void dfs(int u,vector<vector<int>>& graph){

        path.push_back(u);
        if (u == n-1){
            ans.push_back(path);
            path.pop_back();
            return ;
        }

        for(auto ch : graph[u])
                dfs(ch,graph);
               
        path.pop_back();

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        dfs(0,graph);
        return ans;
    }
};