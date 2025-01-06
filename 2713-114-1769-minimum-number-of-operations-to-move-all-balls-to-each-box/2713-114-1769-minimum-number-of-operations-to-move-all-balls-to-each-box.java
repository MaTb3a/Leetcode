import java.util.*;

class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int op = 0, L = 0, R = 0;

        for (int i = 0; i < n; i++) {
            if (boxes.charAt(i) == '1') {
                op += i;
                R++;
            }
        }

        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = op;
            if (boxes.charAt(i) == '1') {
                L++;
                R--;
            }
            op += -R + L;
        }

        return result;
    }
}
