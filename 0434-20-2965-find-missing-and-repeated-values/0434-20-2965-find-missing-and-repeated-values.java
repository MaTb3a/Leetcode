import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        int a = 0;
        int gsum = 0;
        for (int[] row : grid) {
            for (int x : row) {
                int nx = Math.abs(x);
                gsum += nx;
                int r = (nx - 1) / n;
                int c = (nx - 1) % n;
                if (grid[r][c] < 0) {
                    a = nx;
                }
                grid[r][c] *= -1;
            }
        }
        int nSquared = n * n;
        int totalSum = nSquared * (nSquared + 1) / 2;
        int[] result = new int[2];
        result[0] = a;
        result[1] = totalSum - gsum + a;
        return result;
    }
}