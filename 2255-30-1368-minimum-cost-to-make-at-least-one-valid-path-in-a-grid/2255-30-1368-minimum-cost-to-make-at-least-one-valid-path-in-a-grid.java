import java.util.*;

class Solution {
    public int minCost(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        int[][] dist = new int[n][m];
        for (int[] row : dist) Arrays.fill(row, Integer.MAX_VALUE);
        dist[0][0] = 0;

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0], y = cur[1];
            for (int i = 0; i < 4; i++) {
                int ddx = x + dx[i], ddy = y + dy[i];
                if (ddx >= 0 && ddy >= 0 && ddx < n && ddy < m) {
                    int newCost = dist[x][y] + (grid[x][y] == i + 1 ? 0 : 1);
                    if (dist[ddx][ddy] > newCost) {
                        dist[ddx][ddy] = newCost;
                        q.add(new int[]{ddx, ddy});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
}
