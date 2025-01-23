class Solution {
    public int countServers(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[] row = new int[n];
        int[] col = new int[m];
        int cnt = 0;

        // Count servers in each row and column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        // Count servers that can communicate
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
}
