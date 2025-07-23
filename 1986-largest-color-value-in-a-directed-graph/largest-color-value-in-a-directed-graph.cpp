class Solution {
public:
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        queue<int> q;
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> in(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            in[it[1]]++;
        }

        for (int i = 0; i < n; i++)
            if (!in[i])
                q.push(i);

        int cnt = 0,ans =0;
        vector<vector<int>>dp(n,vector<int>(26));
        while (q.size()) {
            int u = q.front();
            q.pop();
            int c = colors[u] - 'a';
            dp[u][c]++;
            ans=max(ans,dp[u][c]);
            cnt++;
            for (int v : adj[u]) {
                for(int j = 0 ; j < 26;j++)
                    dp[v][j] = max(dp[v][j],dp[u][j]);
                in[v]--;
                if (!in[v])
                    q.push(v);
            }
        }
       
        return cnt == n ? ans:-1;
    }
};