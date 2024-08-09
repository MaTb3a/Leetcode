class Solution {
public:
    bool solve(int x ,int y,vector<vector<int>>& grid){

        vector<int>row(3),col(3);
        vector<int>vis(16);
        int d1 = 0 , d2 = 0;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                vis[grid[i+x][y+j]]++;
                row[i]+=grid[x+i][y+j];
                col[j]+=grid[x+i][y+j];
                if(i==j)d1+=grid[x+i][y+j];
                if(i+j == 2)d2+=grid[x+i][y+j];
            }
        }
        if(d1 != d2)return false;
        for(int i = 0 ; i < 3 ; i++)
            if(d1 != row[i] || d1!= col[i])return false;
        for(int i = 1 ; i < 10 ; i++)
            if(vis[i]!=1)return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;
        //[[8,1,6],[3,5,7],[4,9,2]]


        for(int i = 0 ; i < grid.size() ; i++)
            for(int j = 0 ; j < grid[0].size() ; j++)
                if( i + 3 <=  grid.size()  && j +3 <= grid[0].size())
                    cnt+=solve(i,j,grid);
        return cnt;
    }
};