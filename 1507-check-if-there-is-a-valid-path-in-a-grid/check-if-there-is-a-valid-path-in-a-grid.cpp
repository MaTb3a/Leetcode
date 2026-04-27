class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool ports[7][4] = {
        {0, 0, 0, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 1, 0, 0}
    };
    bool visited[305][305];

    bool solve(int x, int y, vector<vector<int>>& grid, int n, int m) {
        if (x == n - 1 && y == m - 1) return true;
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {
                
            bool isValidConnection = ports[grid[x][y]][i] && ports[grid[nx][ny]][(i + 2) % 4];
                if (isValidConnection) {
                    if (solve(nx, ny, grid, n, m)) return true;
                }
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        memset(visited, false, sizeof(visited));
        return solve(0, 0, grid, grid.size(), grid[0].size());
    }
};