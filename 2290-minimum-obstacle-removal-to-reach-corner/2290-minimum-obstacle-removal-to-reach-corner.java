import java.util.*;

class Solution {
    public int minimumObstacles(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[] dist = new int[n * m];
        Arrays.fill(dist, Integer.MAX_VALUE);
        int[] dx = {0, 1, 0, -1, 0};  
        Deque<int[]> q = new LinkedList<>();
        
        dist[0] = 0;
        q.offerFirst(new int[]{0, 0});  
        
        while (!q.isEmpty()) {
            int[] front = q.pollFirst();
            int d = front[0], idx = front[1];
            int i = idx / m, j = idx % m;
            if (i == n - 1 && j == m - 1) {
                return d;
            }
            
            for (int a = 0; a < 4; a++) {
                int r = i + dx[a], c = j + dx[a + 1];
                if (r < 0 || r >= n || c < 0 || c >= m) {
                    continue;
                }
                int d2 = d + grid[r][c];
                int idx2 = r * m + c;
                if (d2 < dist[idx2]) {
                    dist[idx2] = d2;
                    if (grid[r][c] == 0) {
                        q.offerFirst(new int[]{d2, idx2});
                    } else {
                        q.offerLast(new int[]{d2, idx2});
                    }
                }
            }
        }
        
        return -1;
    }
}
