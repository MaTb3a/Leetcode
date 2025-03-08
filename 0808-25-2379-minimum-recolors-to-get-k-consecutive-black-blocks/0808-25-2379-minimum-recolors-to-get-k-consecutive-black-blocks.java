class Solution {
    public int minimumRecolors(String blocks, int k) {
        int w = 0;
        for (int i = 0; i < k; i++) {
            if (blocks.charAt(i) == 'W') w++;
        }
        int ans = w;
        for (int i = k; i < blocks.length(); i++) {
            if (blocks.charAt(i - k) == 'W') w--;
            if (blocks.charAt(i) == 'W') w++;
            ans = Math.min(ans, w);
        }
        return ans;
    }
}