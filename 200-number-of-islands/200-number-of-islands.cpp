class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int vis[301][301];
    int n,m;
    bool valid(int x,int y){
        return x>=0 && y>=0 && x<n && y <m && !vis[x][y];
    }
    void BFS(int x,int y,vector<vector<char>>& grid){
        queue<pair<int,int>>q;
        q.push({x,y});
        vis[x][y]=1;
        while(q.size()){
            pair<int,int>p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int ddx=dx[i]+p.first;
                int ddy=dy[i]+p.second;
                if(valid(ddx,ddy) && grid[ddx][ddy]=='1'){
                    vis[ddx][ddy]=1;
                    q.push({ddx,ddy});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        n= grid.size();
        m= grid[0].size();
        memset(vis,0,sizeof vis);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    BFS(i,j,grid);
                }
            }
        }
        return cnt;
    }
};