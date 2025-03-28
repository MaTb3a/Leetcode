class Solution {
    public int[] maxPoints(int[][] grid, int[] queries) {
        int n = grid.length, m = grid[0].length;
        
        int[][] queryIndices = new int[queries.length][2];
        for (int i = 0; i < queries.length; i++) {
            queryIndices[i] = new int[]{queries[i], i};
        }
        Arrays.sort(queryIndices, (a, b) -> Integer.compare(a[0], b[0]));
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{grid[0][0], 0, 0});
        grid[0][0] = 0;
        
        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};
        
        int[] ans = new int[queries.length];
        int cnt = 0;
        
        for (int[] query : queryIndices) {
            int q = query[0], idx = query[1];
            
            while (!pq.isEmpty() && pq.peek()[0] < q) {
                int[] curr = pq.poll();
                cnt++;
                
                for (int k = 0; k < 4; k++) {
                    int nx = curr[1] + dx[k], ny = curr[2] + dy[k];
                    
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != 0) {
                        pq.offer(new int[]{grid[nx][ny], nx, ny});
                        grid[nx][ny] = 0;
                    }
                }
            }
            
            ans[idx] = cnt;
        }
        
        return ans;
    }
}