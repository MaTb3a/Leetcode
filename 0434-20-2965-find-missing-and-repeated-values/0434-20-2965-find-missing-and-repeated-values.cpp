class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       
        int n = grid.size(),a,gsum = 0;
        for(auto v : grid){
            for(int x : v){
                int nx = abs(x);
                gsum+=nx;
                int r  = (nx-1)/n, c = (nx-1)%n;
                if(grid[r][c] < 0)
                    a = nx;
                grid[r][c]*=-1;
            }
        }
        n*=n;
        int sum = n*(n+1)/2;
        return {a,sum - gsum +a};

    }
};