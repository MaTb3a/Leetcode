class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = 0b1111;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) m &= 0b1110;
                if (mat[i][j] != target[j][n - 1 - i]) m &= 0b1101;
                if (mat[i][j] != target[n - 1 - i][n - 1 - j]) m &= 0b1011;
                if (mat[i][j] != target[n - 1 - j][i]) m &= 0b0111;
                if (m == 0) return false;
            }
        }

        return m != 0;
    }
};
