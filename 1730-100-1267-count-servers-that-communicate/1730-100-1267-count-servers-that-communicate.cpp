class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size(),cnt = 0;
        bitset<500>r,c;
        for(int i = 0 ; i < n ;i++)
            for(int j = 0 ; j < m;j++)
                if(grid[i][j]){
                    r[i] ? r[i+250] =1 : r[i] = 1;
                    c[j] ? c[j+250] =1 : c[j] = 1;
                }
          for(int i = 0 ; i < n ;i++)
            for(int j = 0 ; j < m;j++)
                if(grid[i][j] && (r[i+250] |c[j+250]))cnt++;
        return cnt;

        
    }
};