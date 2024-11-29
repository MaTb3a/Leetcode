import java.util.*;

class Solution {
    public int minimumTime(int[][] grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int n = grid.length, m = grid[0].length;
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        boolean[][] visited = new boolean[n][m];
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0])); 
        pq.offer(new int[]{0, 0, 0});

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int curTime = top[0], x = top[1], y = top[2];

            if (x == n - 1 && y == m - 1) {
                return curTime;
            }
            if (visited[x][y]) {
                continue;
            }
            visited[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int wastedTime = (grid[nx][ny] - curTime) % 2 == 0 ? 1 : 0;
                    int maxTime = Math.max(curTime + 1, grid[nx][ny] + wastedTime);
                    pq.offer(new int[]{maxTime, nx, ny});
                }
            }
        }

        return -1;
    }
}
