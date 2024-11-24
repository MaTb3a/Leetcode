class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long totalSum = 0;
        int minValue = Integer.MAX_VALUE;
        int negativeCount = 0;

        for (int[] row : matrix) {
            for (int x : row) {
                totalSum += Math.abs(x);
                minValue = Math.min(minValue, Math.abs(x));
                if (x < 0) {
                    negativeCount++;
                }
            }
        }

        return totalSum - (negativeCount % 2 != 0 ? 2L * minValue : 0);
    }
}
