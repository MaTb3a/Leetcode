class Solution {
public:
    vector<int>dir = {1,0,-1,0,1};
    void dfs(int i,int j,vector<vector<char>>&grid){
        if(i<0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')return ;
        grid[i][j] = '0';
        for(int k = 0 ; k < 4;k++)
            dfs(i+dir[k],j+dir[k+1],grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0 ; i < grid.size();i++){
            for(int j = 0 ; j < grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};