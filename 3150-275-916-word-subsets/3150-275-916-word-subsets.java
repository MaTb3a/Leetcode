import java.util.*;

class Solution {
    private int[] solve(String s) {
        int[] freq = new int[26];
        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }
        return freq;
    }

    public List<String> wordSubsets(String[] words1, String[] words2) {
        int[] frq = new int[26];
        for (String word : words2) {
            int[] tmp = solve(word);
            for (int i = 0; i < 26; i++) {
                frq[i] = Math.max(frq[i], tmp[i]);
            }
        }

        List<String> result = new ArrayList<>();
        for (String word : words1) {
            int[] tmp = solve(word);
            boolean isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (frq[i] > tmp[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.add(word);
            }
        }

        return result;
    }
}
