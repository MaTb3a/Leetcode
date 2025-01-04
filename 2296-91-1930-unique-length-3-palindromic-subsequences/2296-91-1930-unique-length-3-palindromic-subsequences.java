import java.util.*;

class Solution {
    public int countPalindromicSubsequence(String s) {
        int[] left = new int[26];
        int[] right = new int[26];
        Arrays.fill(left, -1);

        for (int i = 0; i < s.length(); i++) {
            int idx = s.charAt(i) - 'a';
            if (left[idx] == -1) {
                left[idx] = i;
            } else {
                right[idx] = i;
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (right[i] == 0) continue;
            boolean[] visited = new boolean[26];
            for (int j = left[i] + 1; j < right[i]; j++) {
                int idx = s.charAt(j) - 'a';
                if (!visited[idx]) {
                    visited[idx] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
}
