
class Solution {
    private boolean check(int[][] rectangles, int d) {
        Arrays.sort(rectangles, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[d], b[d]);
            }
        });
        
        int cnt = 0;
        int mx = rectangles[0][d + 2]; 
        for (int i = 1; i < rectangles.length; i++) {
            if (mx <= rectangles[i][d]) {
                cnt++;
            }
            mx = Math.max(mx, rectangles[i][d + 2]);
        }
        return cnt >= 2;
    }

    public boolean checkValidCuts(int n, int[][] rectangles) {
        return check(rectangles, 0) || check(rectangles, 1);
    }
}