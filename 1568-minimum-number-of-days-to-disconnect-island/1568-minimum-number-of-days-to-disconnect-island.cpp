class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis){
       
        if( i < 0 || j < 0 || i >=n || j >=m   || !grid[i][j] || vis[i][j] )return ;
        
        vis[i][j] = true;
        dfs(i+1,j,grid,vis);dfs(i-1,j,grid,vis); 
        dfs(i,j+1,grid,vis);dfs(i,j-1,grid,vis);
    }
    int connected_component(vector<vector<int>>& grid){
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int island = 0;
          for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] && !vis[i][j]){
                    island++;
                    dfs(i,j,grid,vis);
                }
            }
        return island;
    }
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(connected_component(grid)!=1)return 0;

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    if(connected_component(grid) != 1)return 1;
                    grid[i][j] = 1;
                }
            }
        return 2;
    }
};