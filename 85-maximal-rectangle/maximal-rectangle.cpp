
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j) 
                pre[i + 1][j + 1] = (matrix[i][j] - '0') + pre[i + 1][j];
          
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j) 
                pre[i + 1][j + 1] += pre[i][j + 1];
          
        
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int i2 = n; i2 >= i; --i2) {
                    int l = j;
                    int r = m;
                    while (l <= r) {
                        int md = l + (r - l) / 2;
                        int j2 = md;
                        
                        int regionSum = pre[i2][j2] - pre[i2][j - 1] - pre[i - 1][j2] + pre[i - 1][j - 1];
                        int expectedArea = (j2 - j + 1) * (i2 - i + 1);
                        
                        if (regionSum == expectedArea) {
                            ans = max(ans, expectedArea);
                            l = md + 1;
                        } else {
                            r = md - 1; 
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};