class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<int> v;
                for (int x = i; x < i + k; x++)
                    for (int y = j; y < j + k; y++)
                        v.push_back(grid[x][y]);

                sort(v.begin(), v.end());
                v.erase(unique(v.begin(), v.end()), v.end());

                if (v.size() <= 1) {
                    ans[i][j] = 0;
                } else {
                    int mn = INT_MAX;
                    for (int p = 0; p < (int)v.size() - 1; p++)
                        mn = min(mn, v[p+1] - v[p]);
                    ans[i][j] = mn;
                }
            }
        }
        return ans;
    }
};