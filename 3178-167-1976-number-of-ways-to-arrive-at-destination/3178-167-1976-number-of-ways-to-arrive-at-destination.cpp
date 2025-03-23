class Solution {
public:
    const int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) { 
        vector<vector<pair<int,int>>>adj(n);
        for(auto road : roads){ 
            int u = road[0],v = road[1],t = road[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }

        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pr;
        pr.push({0,0});
        while(pr.size()){ 
            auto [time,u] = pr.top();pr.pop(); 
            if(time > dist[u])continue;
            for(auto [v ,t] : adj[u]){
                if(dist[v] > time + t){ 
                    dist[v] = time + t;
                    pr.push({dist[v],v});
                    ways[v] = ways[u];
                }
                else if(dist[v] == time + t){
                     ways[v] += ways[u];
                     if(ways[v] > mod)ways[v]-=mod;
                }

            }

        }
        return ways[n-1];

    }
};