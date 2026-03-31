class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int j = y ; j < y+k ;j++)
            for(int i = x , i2 = x+k -1; i < i2;i++,i2--)
                swap(grid[i][j],grid[i2][j]);
            
        return grid;
    }
};