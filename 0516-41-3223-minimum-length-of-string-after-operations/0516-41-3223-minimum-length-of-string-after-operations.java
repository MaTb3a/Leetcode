class Solution {
    public int minimumLength(String s) {
        int mask1 = 0, mask2 = 0;
        int removes = 0;

        for (char ch : s.toCharArray()) {
            int bit = 1 << (ch - 'a');
            if ((mask1 & bit) == 0) {
                mask1 |= bit;
            } else if ((mask2 & bit) == 0) {
                mask2 |= bit;
            } else {
                removes += 2;
                mask1 &= ~bit;
            }
        }

        return s.length() - removes;
    }
}
