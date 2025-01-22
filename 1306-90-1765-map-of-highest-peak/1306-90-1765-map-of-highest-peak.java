
class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int n = isWater.length, m = isWater[0].length;
        boolean[][] visited = new boolean[n][m];
        Queue<int[]> q = new LinkedList<>();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    q.add(new int[]{i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        int[] directions = {-1, 0, 1, 0, -1};
        
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int x = cell[0], y = cell[1];
            for (int i = 0; i < 4; i++) {
                int dx = x + directions[i];
                int dy = y + directions[i + 1];
                if (dx >= 0 && dy >= 0 && dx < n && dy < m && !visited[dx][dy]) {
                    visited[dx][dy] = true;
                    isWater[dx][dy] = isWater[x][y] + 1;
                    q.add(new int[]{dx, dy});
                }
            }
        }
        
        return isWater;
    }
}
