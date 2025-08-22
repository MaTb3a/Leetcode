class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int i1=n,j1 = m,i2 = 0,j2= 0;
        for(int i = 0 ; i < n;i++){
            for(int j = 0 ; j < m;j++){
                if(grid[i][j]){
                    i1=min(i1,i);
                    j1=min(j1,j);
                    i2=max(i2,i);
                    j2=max(j2,j);
                }
            }
        }
        return (i2-i1+1) * (j2-j1+1);
    }
};