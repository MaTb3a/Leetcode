class Solution {
public:
    // connected component
    
    bool vis[301][301];
    int n,m;
    
    void solve(int x,int y,vector<vector<char>>& grid){
        if( x<0 || y <0 || x>=n || y>=m || vis[x][y] || grid[x][y]=='0')
            return ;
        vis[x][y]=1;
        
        solve(x+1,y,grid);
        solve(x-1,y,grid);
        solve(x,y+1,grid);
        solve(x,y-1,grid);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size(); // rows
        m=grid[0].size(); // columns
        int cnt=0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    cnt++;
                     solve(i,j,grid);
                }
        return cnt;
       
    }
};