class Solution {
public:
    bool valid(int x,int y,int n,int m){
        return x>=0 && y >= 0 && x <n && y <m;
    }
    int solve(int x,int y,int n,int m, vector<vector<int>>& grid){
        vector<int>dir = {-1,0,1,0,-1};
        int cnt = 4;
        for(int i = 0 ; i < 4;i++){
            int dx = x+dir[i];
            int dy = y+dir[i+1];
            if(valid(dx,dy,n,m) && grid[dx][dy]==1)cnt--;
        }
        return cnt;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for(int i = 0 ; i < n;i++)
            for(int j = 0 ; j < m;j++)
                if(grid[i][j])cnt+=solve(i,j,n,m,grid);
        
        return cnt;
    }
};