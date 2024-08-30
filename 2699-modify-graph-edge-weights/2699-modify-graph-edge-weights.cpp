class Solution {
public:
    int Dijkstra(int n,int src,int dest,vector<vector<pair<int,int>>>graph){
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>pr;
       
        vector<int>distance(n,2e9);
        distance[src] = 0;
        pr.push({0,src});  // w , node

        while(pr.size()){
            auto [dist,node] = pr.top();pr.pop();

            if(dist > distance[node])continue;

            for(auto [child,weight] : graph[node]){
                if(distance[child] > dist + weight){
                    distance[child] = dist + weight;
                    pr.push({distance[child],child});
                }
            }
        }
        return distance[dest];   
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        // Dijsktra
        // N log(N);

        vector<vector<pair<int,int>>>graph(n);
        for(auto edge : edges){
            if(edge[2]!=-1)
                graph[edge[0]].push_back({edge[1],edge[2]}),
                graph[edge[1]].push_back({edge[0],edge[2]});
        }

        int cutDist = Dijkstra(n,source,destination,graph);

        if(cutDist  < target)return vector<vector<int>>();

        bool valid = (cutDist  ==  target);

        for(auto &edge : edges){
            if(edge[2]!=-1)continue;
            edge[2] = valid ? 2e9 : 1;

            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});

            if(!valid){
                int newDist = Dijkstra(n,source,destination,graph);
                if(newDist <= target){ // 11 37
                    valid = true;
                    edge[2] += target-newDist;
                }
            }

        }
        return valid ? edges :  vector<vector<int>>();

    }
};