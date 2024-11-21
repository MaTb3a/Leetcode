class Solution {
    public void dfs(int x, int y, int[][] grid, int m, int n, char direction) {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] > 1) {
            return;
        }
        grid[x][y] = 1;

        if (direction == 'U') {
            dfs(x - 1, y, grid, m, n, direction);
        }
        if (direction == 'D') {
            dfs(x + 1, y, grid, m, n, direction);
        }
        if (direction == 'R') {
            dfs(x, y + 1, grid, m, n, direction);
        }
        if (direction == 'L') {
            dfs(x, y - 1, grid, m, n, direction);
        }
    }

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] grid = new int[m][n];

        for (int[] wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }

        for (int[] guard : guards) {
            grid[guard[0]][guard[1]] = 3;
        }

        for (int[] guard : guards) {
            dfs(guard[0] - 1, guard[1], grid, m, n, 'U');
            dfs(guard[0] + 1, guard[1], grid, m, n, 'D');
            dfs(guard[0], guard[1] + 1, grid, m, n, 'R');
            dfs(guard[0], guard[1] - 1, grid, m, n, 'L');
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
}
