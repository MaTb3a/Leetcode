int dx[] = {0, 1, 0, -1, 0};
class Solution {
public:
    static int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dist(n * m, 0x3f3f3f3f);
        deque<pair<int, int>> q;
        dist[0] = 0;
        q.push_front({0, 0});
        while (!q.empty()) {
            auto [d, idx] = q.front();
            q.pop_front();
            int i = idx / m, j = idx % m;
            if (i == n - 1 && j == m - 1) return d;
            for (int a = 0; a < 4; ++a) {
                int r = i + dx[a];
                int c = j + dx[a + 1];
                if (r < 0 || r >= n || c < 0 || c >= m) continue;
                int d2 = d + grid[r][c];
                int idx2 = r * m + c;
                if (d2 < dist[idx2]) {
                    dist[idx2] = d2;
                    if (grid[r][c] == 0) q.push_front({d2, idx2});
                    else q.push_back({d2, idx2});
                }
            }
        }
        return -1;
    }
};