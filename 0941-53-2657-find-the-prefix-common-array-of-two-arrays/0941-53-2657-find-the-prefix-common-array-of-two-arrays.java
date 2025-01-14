import java.util.*;

class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        boolean[] vis = new boolean[51];
        boolean[] vis2 = new boolean[51];
        int[] result = new int[A.length];

        for (int i = 0; i < A.length; i++) {
            vis[A[i]] = true;
            vis2[B[i]] = true;
            int count = 0;
            for (int j = 1; j <= 50; j++) {
                if (vis[j] && vis2[j]) {
                    count++;
                }
            }
            result[i] = count;
        }

        return result;
    }
}
