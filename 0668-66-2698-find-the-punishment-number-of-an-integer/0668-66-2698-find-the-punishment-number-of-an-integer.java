class Solution {
    private boolean solve(int num, int target) {
        if (num == target) return true;
        if (num < target || target < 0) return false;
        return solve(num / 10, target - num % 10) ||
               solve(num / 100, target - num % 100) ||
               solve(num / 1000, target - num % 1000);
    }

    public int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (solve(i * i, i)) {
                ans += i * i;
            }
        }
        return ans;
    }

    // Example Usage:
    // Solution sol = new Solution();
    // System.out.println(sol.punishmentNumber(n));
}
