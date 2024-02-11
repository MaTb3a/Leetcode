class Solution {
public:
    int n,m;
    int dp[71][71][71];
    
    int solve(int x1,int y1,int x2,int y2,vector<vector<int>>& grid){
        if( y1 < 0 || y1 ==m || y2 <0 || y2 ==m || (x1==n && x2==n)) return 0;
        int &ret = dp[x1][y1][y2];
        if(~ret)return ret;
        ret = -1e9;
        
        ret=max(ret,solve(x1+1,y1,x2+1,y2,grid)+ ((x1==x2 && y1 == y2) ? grid[x1][y1] : grid[x1][y1]+grid[x2][y2]));
        ret=max(ret,solve(x1+1,y1,x2+1,y2+1,grid)+ ((x1==x2 && y1 == y2) ? grid[x1][y1] : grid[x1][y1]+grid[x2][y2]));
        ret=max(ret,solve(x1+1,y1,x2+1,y2-1,grid)+ ((x1==x2 && y1 == y2) ? grid[x1][y1] : grid[x1][y1]+grid[x2][y2]));
        
        ret=max(ret,solve(x1+1,y1+1,x2+1,y2,grid)+ ((x1==x2 && y1 == y2) ? grid[x1][y1] : grid[x1][y1]+grid[x2][y2]));
        ret=max(ret,solve(x1+1,y1+1,x2+1,y2+1,grid)+ ((x1==x2 && y1 == y2) ? grid[x1][y1] : grid[x1][y1]+grid[x2][y2]));
        ret=max(ret,solve(x1+1,y1+1,x2+1,y2-1,grid)+ ((x1==x2 && y1 == y2) ? grid[x1][y1] : grid[x1][y1]+grid[x2][y2]));

        ret=max(ret,solve(x1+1,y1-1,x2+1,y2-1,grid)+ ((x1==x2 && y1 == y2) ? grid[x1][y1] : grid[x1][y1]+grid[x2][y2]));
        ret=max(ret,solve(x1+1,y1-1,x2+1,y2+1,grid)+ ((x1==x2 && y1 == y2) ? grid[x1][y1] : grid[x1][y1]+grid[x2][y2]));
        ret=max(ret,solve(x1+1,y1-1,x2+1,y2,grid)+ ((x1==x2 && y1 == y2) ? grid[x1][y1] : grid[x1][y1]+grid[x2][y2]));

        return ret ;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof dp);
        
        return solve(0,0,0,m-1,grid);
    }
};