import java.util.*;

class Solution {
    public int[] leftmostBuildingQueries(int[] heights, int[][] queries) {
        int n = heights.length;
        int m = queries.length;
        List<List<int[]>> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            v.add(new ArrayList<>());
        }
        int[] ans = new int[m];
        Arrays.fill(ans, -1);

        for (int i = 0; i < m; i++) {
            int x = queries[i][0], y = queries[i][1];
            if (x > y) {
                int temp = x;
                x = y;
                y = temp;
            }
            if (x == y || heights[x] < heights[y]) {
                ans[i] = y;
            } else {
                v.get(y).add(new int[] { Math.max(heights[x], heights[y]), i });
            }
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < n; i++) {
            for (int[] it : v.get(i)) {
                pq.add(it);
            }
            while (!pq.isEmpty() && pq.peek()[0] < heights[i]) {
                ans[pq.poll()[1]] = i;
            }
        }

        return ans;
    }
}
