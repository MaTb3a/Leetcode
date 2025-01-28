class Solution {
public:
    

    int DFS(int x,int y,vector<vector<int>>& grid){
        if(x < 0 || x >= grid.size() || y  < 0 || y >= grid[0].size() || !grid[x][y])return 0;
        int ans = grid[x][y];
        grid[x][y] = 0;
        return DFS(x+1,y,grid) +  DFS(x-1,y,grid) +  DFS(x,y+1,grid)+  DFS(x,y-1,grid) + ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int mx = 0;
        for(int i = 0 ; i < grid.size();i++)
            for(int j = 0 ; j < grid[0].size();j++)
                if(grid[i][j])mx=max(mx,DFS(i,j,grid));
        return mx;
    }
};