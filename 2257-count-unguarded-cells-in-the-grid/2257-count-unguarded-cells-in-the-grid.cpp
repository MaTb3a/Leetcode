class Solution {
public:

    void dfs(int x,int y,vector<vector<int>>&grid,int m,int n,char dir){
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] > 1)return ;
         grid[x][y] = 1;
         if(dir =='U')dfs(x-1,y,grid,m,n,dir);
         if(dir =='D')dfs(x+1,y,grid,m,n,dir);
         if(dir =='R')dfs(x,y+1,grid,m,n,dir);
         if(dir =='L')dfs(x,y-1,grid,m,n,dir);
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n));

        for(auto it : walls)
            grid[it[0]][it[1]] = 2;
         for(auto it : guards)
            grid[it[0]][it[1]] = 3;
        
         for(auto it : guards){
            dfs(it[0]-1,it[1],grid,m,n,'U');
            dfs(it[0]+1,it[1],grid,m,n,'D');
            dfs(it[0],it[1]+1,grid,m,n,'R');
            dfs(it[0],it[1]-1,grid,m,n,'L');
         }
        
        int cnt = 0;
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ;j++)
                cnt+=!grid[i][j];
        return cnt;
            
    }
};