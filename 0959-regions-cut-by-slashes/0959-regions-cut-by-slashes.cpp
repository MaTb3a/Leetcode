class Solution {
public:
    int n2,m2;
    vector<vector<bool>>grid2;
    void dfs(int i,int j){
        if( i < 0 || j < 0 || i >= n2 || j >= m2 || grid2[i][j])return ;
        grid2[i][j] = true;
        dfs(i+1,j);dfs(i-1,j);
        dfs(i,j+1);dfs(i,j-1);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        n2 = n *3;
        m2 = m *3;
        grid2 = vector<vector<bool>>(n2,vector<bool>(m2));

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++){
                int ii = i * 3;
                int jj = j * 3;
                if(grid[i][j]=='\\')
                    grid2[ii][jj] =  grid2[ii+1][jj+1] = grid2[ii+2][jj+2] = true;
                if(grid[i][j] == '/')
                    grid2[ii][jj+2] = grid2[ii+1][jj+1] = grid2[ii+2][jj] = true;
            }
        int cnt = 0;
        for(int i = 0 ; i < n2 ; i++)
            for(int j = 0 ; j < m2;j++)
                if(!grid2[i][j])
                    cnt++,dfs(i,j);
        return cnt;
    }
};