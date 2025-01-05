class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] v = new int[n + 1];

        for (int[] shift : shifts) {
            int l = shift[0], r = shift[1], d = shift[2];
            v[l] += d == 1 ? 1 : -1;
            if (r + 1 < n) {
                v[r + 1] += d == 1 ? -1 : 1;
            }
        }

        char[] chars = s.toCharArray();
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                v[i] += v[i - 1];
            }
            chars[i] = (char) (((chars[i] - 'a' + v[i]) % 26 + 26) % 26 + 'a');
        }

        return new String(chars);
    }
}
