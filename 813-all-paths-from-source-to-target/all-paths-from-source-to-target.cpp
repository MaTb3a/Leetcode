class Solution {
public:
    vector<bool>vis;
    vector<vector<int>>ans;
    vector<int>path;
    int n;
    void dfs(int u,vector<vector<int>>& graph){

        if (u == n-1){
            ans.push_back(path);
            return ;
        }

        for(auto ch : graph[u]){
            if(!vis[ch]){
                vis[ch] = true;
                path.push_back(ch);
                dfs(ch,graph);
                path.pop_back();
                vis[ch] = false;
            }
        }

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vis = vector<bool>(n);

        path.push_back(0);
        dfs(0,graph);
        return ans;
    }
};