class Solution {
    private int DFS(int x, int y, int[][] grid) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] == 0) {
            return 0;
        }
        int ans = grid[x][y];
        grid[x][y] = 0;
        return ans
            + DFS(x + 1, y, grid)
            + DFS(x - 1, y, grid)
            + DFS(x, y + 1, grid)
            + DFS(x, y - 1, grid);
    }

    public int findMaxFish(int[][] grid) {
        int mx = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] > 0) {
                    mx = Math.max(mx, DFS(i, j, grid));
                }
            }
        }
        return mx;
    }
}
