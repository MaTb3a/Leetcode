class Solution {
    public boolean canConstruct(String s, int k) {
        if (k > s.length()) {
            return false;
        }

        int freq = 0;
        for (char ch : s.toCharArray()) {
            freq ^= (1 << (ch - 'a'));
        }

        return Integer.bitCount(freq) <= k;
    }
}
