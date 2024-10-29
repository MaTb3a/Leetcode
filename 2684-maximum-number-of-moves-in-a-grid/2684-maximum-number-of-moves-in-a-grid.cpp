class Solution {
public:
    int n,m;
    int dp[1001][2];
   
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for(int i = 0 ; i < n ;i++)
            dp[i][0] = 1;
        
        int ret= 0;
        for(int j = 1 ; j < m ; j++){
            int jj = j&1; // 0 1 
            for(int i = 0 ; i < n ;i++){
                dp[i][jj] = 0;
                if( i+1 < n && grid[i][j] > grid[i+1][j-1] && dp[i+1][!jj])
                    dp[i][jj] = max(dp[i][jj], dp[i+1][!jj]+1);

                if(grid[i][j] > grid[i][j-1] && dp[i][!jj])
                    dp[i][jj] = max(dp[i][jj], dp[i][!jj]+1);

                if(i-1 >= 0 && grid[i][j] > grid[i-1][j-1] && dp[i-1][!jj])
                    dp[i][jj] = max(dp[i][jj], dp[i-1][!jj]+1);
                ret=max(ret,dp[i][jj]-1);
            }
        }
        return ret;
    }
};