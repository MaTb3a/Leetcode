class Solution {
    public int maxScore(String s) {
        int zeros = 0, ones = 0, ans = 0;

        // Count total number of '1's in the string
        for (char ch : s.toCharArray()) {
            if (ch == '1') ones++;
        }

        // Traverse the string excluding the last character
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == '1') {
                ones--;
            } else {
                zeros++;
            }
            ans = Math.max(ans, ones + zeros);
        }

        return ans;
    }
}
