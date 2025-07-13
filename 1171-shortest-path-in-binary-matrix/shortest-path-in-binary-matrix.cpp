 // 3 BFS / Dijskstra / floyd 
        // n^2 / n^2 log(n) / n^3

     

        /*

    n = size(grid)
            dx = {-1,1,0,0,-1,-1,1,1}
            dy = {0,0,1,-1,1,-1,-1,1}
            
            queue(x,y) => 0,0

            dist  = 2d grid[n][n] => INF

            loop(q):
                x,y = q.top 
                q pop

                // loop( 8):
                    ddx
                    ddy
                    if valid  && dist[ddx][ddy] >  ist[x][y]+1  && !grid[ddx][ddy]:
                        dist[ddx][ddy] > dist[x][y] + 1 
                        push(ddx, ddy)

        */


class Solution {
public:
    bool valid(int x,int y,int n){
        return x >=0 && y >=0 && x <n && y<n;
    }
    int dx[8] = {-1,1,0,0,-1,-1,1,1};
    int dy[8] = {0,0,1,-1,1,-1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0])return -1;
        vector<vector<int>>dist(n,vector<int>(n,0x3f3f3f3f)); // M (n^2)
        dist[0][0] = 1;

        queue<pair<int,int>>q;
        q.push({0,0});

        while(q.size()){ // n^2
            auto [x,y] = q.front();
            q.pop();
            for(int i = 0 ; i < 8 ; i++){ // 8
                int ddx = dx[i] + x;
                int ddy = dy[i] + y;
                if(valid(ddx,ddy,n) && !grid[ddx][ddy] &&  dist[ddx][ddy] >  dist[x][y]+1){
                     dist[ddx][ddy] =  dist[x][y]+1;
                     q.push({ddx,ddy}); 
                }
            }
        }
        return dist[n-1][n-1] == 0x3f3f3f3f ? -1 : dist[n-1][n-1];
    }
};