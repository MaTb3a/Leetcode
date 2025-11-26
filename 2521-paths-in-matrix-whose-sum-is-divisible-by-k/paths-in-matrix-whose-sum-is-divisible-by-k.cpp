class Solution {
public: 
    int M = 1e9+7;
    int n,m;
    vector<vector<int>>dp[50];
    int solve(int i,int j,int mod,int k,vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return 0;
        }
        if (dp[mod][i][j]!=-1)return dp[mod][i][j];

        if (i==n-1 && j == m-1){
            return (grid[i][j]+mod)%k == 0;
        }
        int ret = solve(i+1,j,(mod+grid[i][j])%k,k,grid);
        ret = (ret+solve(i,j+1,(mod+grid[i][j])%k,k,grid))%M;
        return dp[mod][i][j] = ret;

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
         n = grid.size();
         m = grid[0].size();
        for(int i = 0 ; i < 50;i++)
            dp[i] = vector<vector<int>>(n,vector<int>(m,-1));
        return solve(0,0,0,k,grid);

        


    }
};