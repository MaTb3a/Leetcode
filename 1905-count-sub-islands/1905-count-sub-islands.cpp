class Solution {
public:
    int n,m;
    bool dfs(int x,int y,vector<vector<int>>& grid1,vector<vector<int>>& grid2){
        if(x < 0 || y < 0 || x >=n || y >= m)return 1;
        if(grid2[x][y] && !grid1[x][y])return 0;
        if(!grid1[x][y] || !grid2[x][y])return 1;
        grid1[x][y] = grid2[x][y] = 0;
        return dfs(x+1,y,grid1,grid2) & dfs(x-1,y,grid1,grid2) & dfs(x,y+1,grid1,grid2) & dfs(x,y-1,grid1,grid2);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size(), m = grid1[0].size();
        int islands = 0;
        for(int i = 0 ; i < n ;i++)
            for(int j = 0 ; j < m ;j++)
                if(grid1[i][j] && grid2[i][j])
                    islands+=dfs(i,j,grid1,grid2);
        return islands;
    }
};