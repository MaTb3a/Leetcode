class Solution {
    public int maximumCandies(int[] candies, long k) {
        int st = 1;
        int ed = max(candies);
        int cur = 0;

        while (st <= ed) {
            int md = (st + ed) / 2;
            if (ok(candies, md, k)) {
                cur = md;
                st = md + 1;
            } else {
                ed = md - 1;
            }
        }
        return cur;
    }

    private boolean ok(int[] candies, int md, long k) {
        long cnt = 0;
        for (int x : candies) {
            cnt += x / md;
        }
        return cnt >= k;
    }

    private int max(int[] arr) {
        int maxVal = Integer.MIN_VALUE;
        for (int num : arr) {
            if (num > maxVal) {
                maxVal = num;
            }
        }
        return maxVal;
    }

    
}