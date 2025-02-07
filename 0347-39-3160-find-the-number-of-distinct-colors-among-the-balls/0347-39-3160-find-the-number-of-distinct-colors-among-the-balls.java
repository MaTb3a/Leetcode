import java.util.*;

class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        int n = queries.length;
        int[] result = new int[n];
        Map<Integer, Integer> ballColorMap = new HashMap<>();
        Map<Integer, Integer> colorCount = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int ball = queries[i][0], color = queries[i][1];

            if (ballColorMap.containsKey(ball)) {
                int oldColor = ballColorMap.get(ball);
                colorCount.put(oldColor, colorCount.get(oldColor) - 1);
                if (colorCount.get(oldColor) == 0) {
                    colorCount.remove(oldColor);
                }
            }

            colorCount.put(color, colorCount.getOrDefault(color, 0) + 1);
            ballColorMap.put(ball, color);
            result[i] = colorCount.size();
        }

        return result;
    }
}
