class Solution {
public:
   int n, m, ans;
    void solve(vector<vector<int>> & mat, int i, int j) {
        if (j < 0 || j >= m)return ;
        if (i == n) {
            ans = j;
            return ;
        }
        if (mat[i][j] == 1 && j + 1 < m && mat[i][j + 1] == 1)
            solve(mat, i + 1, j + 1);
        if (mat[i][j] == -1 && j - 1 >= 0 && mat[i][j - 1] == -1)
            solve(mat, i + 1, j - 1);
    }
    vector<int> findBall(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        vector<int> res;
        for (int j = 0; j < m; ++j) {
            ans = -1;
            solve(mat, 0, j);
            res.push_back(ans);
        }
        return res;
    }
};