class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int m = matrix[0].length;
        int maxCount = 0;
        HashMap<String, Integer> map = new HashMap<>();
        
        for (int[] row : matrix) {
            StringBuilder original = new StringBuilder();
            StringBuilder flipped = new StringBuilder();
            for (int cell : row) {
                original.append(cell);
                flipped.append(1 - cell);
            }
            String orgStr = original.toString();
            String flipStr = flipped.toString();
            
            map.put(orgStr, map.getOrDefault(orgStr, 0) + 1);
            map.put(flipStr, map.getOrDefault(flipStr, 0) + 1);
            
            maxCount = Math.max(maxCount, map.get(orgStr));
            maxCount = Math.max(maxCount, map.get(flipStr));
        }
        
        return maxCount;
    }
}
