class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
       

        vector<vector<pair<int,double>>>adj(n);
        for(int i = 0 ; i < edges.size();i++){
            int from = edges[i][0],to = edges[i][1];
            adj[from].push_back({to,succProb[i]});
            adj[to].push_back({from,succProb[i]});
        }

         // Dijkstra
         // set priorty
         priority_queue<pair<double,int>>pr;
         vector<double>dist(n);
         dist[start_node] = 1;
         pr.push({1,start_node});

         while(pr.size()){
            auto curNode = pr.top();pr.pop();
            if(curNode.second == end_node)return curNode.first;
            for(int j = 0; j < adj[curNode.second].size();j++){
                double curDist = adj[curNode.second][j].second;
                int to = adj[curNode.second][j].first;
                if(curDist * curNode.first  > dist[to] ){
                    dist[to] = curDist * curNode.first;
                    pr.push({dist[to],to});
                }
            }
         }
         return dist[end_node];
    }
};