class Solution {
    public int minimizeXor(int num1, int num2) {
        int diff = Integer.bitCount(num2) - Integer.bitCount(num1);
        for (int i = 0; i < 32 && diff != 0; i++) {
            if (diff > 0 && (num1 & (1 << i)) == 0) {
                diff--;
                num1 ^= (1 << i);
            } else if (diff < 0 && (num1 & (1 << i)) != 0) {
                diff++;
                num1 ^= (1 << i);
            }
        }
        return num1;
    }
}
