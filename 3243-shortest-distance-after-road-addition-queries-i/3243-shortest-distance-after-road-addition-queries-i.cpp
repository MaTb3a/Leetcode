class Solution {
public:
    vector<int>adj[500];
    int BFS(int n){
        queue<int>q; 
        q.push(0); // src,dist
        vector<int>dist(n,0x3f3f3f3f);
        dist[0] = 0;
        while(q.size()){
            int city = q.front();
            q.pop();
            if(city == n-1)return dist[city];
            for(int child : adj[city]){
                if(dist[child] > dist[city] +1){
                    dist[child] = dist[city] +1;
                    q.push(child);
                }
            }
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        for(int i = 1 ; i < n;i++)
            adj[i-1].push_back(i);
        
        vector<int>ans;
        for(auto bridge : queries){ // Q
             adj[bridge[0]].push_back(bridge[1]); // O
             ans.push_back(BFS(n)); // E+V
        }
        return ans;
    }
};