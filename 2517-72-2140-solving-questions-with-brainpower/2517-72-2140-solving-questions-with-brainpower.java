class Solution {
    private long[] memo;
    private int[][] questions;
    
    public long mostPoints(int[][] questions) {
        this.questions = questions;
        int n = questions.length;
        memo = new long[n + 1];
        Arrays.fill(memo, -1);
        return solve(0);
    }
    
    private long solve(int i) {
        if (i >= questions.length) {
            return 0;
        }
        
        if (memo[i] != -1) {
            return memo[i];
        }
        
        long skip = solve(i + 1);
        long solve = questions[i][0] + solve(i + questions[i][1] + 1);
        
        memo[i] = Math.max(skip, solve);
        return memo[i];
    }
}