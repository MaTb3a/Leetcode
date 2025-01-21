class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long b = accumulate(grid[0].begin(),grid[0].end(),0LL), a = 0,ans = 1e18;
        for(int i = 0 ; i < grid[0].size();i++){
            b-=grid[0][i];
            ans=min(ans, max(a,b));
            a+=grid[1][i];
        }
        return ans;

    }
};