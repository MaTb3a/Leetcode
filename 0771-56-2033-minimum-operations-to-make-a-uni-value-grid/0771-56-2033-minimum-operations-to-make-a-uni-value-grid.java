class Solution {
    public int minOperations(int[][] grid, int x) {
        int mod = grid[0][0] % x;
        int sz = grid.length * grid[0].length;
        int[] frq = new int[10001];
        
        for (int[] row : grid) {
            for (int val : row) {
                if (val % x != mod) {
                    return -1;
                }
                frq[val]++;
            }
        }
        
        int md = 0, ans = 0;
        for (int i = 0; i < 10001; i++) {
            ans += frq[i];
            if (ans * 2 >= sz) {
                md = i;
                break;
            }
        }
        
        ans = 0;
        for (int i = 0; i < 10001; i++) {
            ans += Math.abs(i - md) * frq[i];
        }
        
        return ans / x;
    }
}