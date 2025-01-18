class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<int> dist(n * m, 0xFFFF);  
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        deque<int> dq;  
        dq.push_front(0);
        dist[0] = 0;
        
        while(!dq.empty()) {
            int idx = dq.front();
            dq.pop_front();
            
            int x = idx / m;
            int y = idx % m;
            
            if(x == n-1 && y == m-1) return dist[idx];
            
            int curCost = dist[idx];
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                
                int nidx = nx * m + ny;
                int newCost = curCost + (grid[x][y] == i+1 ? 0 : 1);
                
                if(dist[nidx] > newCost) {
                    dist[nidx] = newCost;
                    if(grid[x][y] == i+1) {
                        dq.push_front(nidx);
                    } else {
                        dq.push_back(nidx);
                    }
                }
            }
        }
        
        return dist[n * m - 1];
    }
};