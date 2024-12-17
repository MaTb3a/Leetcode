import java.util.*;

class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) freq[c - 'a']++;

        PriorityQueue<Character> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < 26; i++) if (freq[i] > 0) pq.add((char) (i + 'a'));

        StringBuilder result = new StringBuilder();

        while (!pq.isEmpty()) {
            char largest = pq.poll();
            int idx = largest - 'a';
            int count = Math.min(repeatLimit, freq[idx]);
            result.append(String.valueOf(largest).repeat(count));
            freq[idx] -= count;

            if (freq[idx] > 0 && !pq.isEmpty()) {
                char nextLargest = pq.poll();
                result.append(nextLargest);
                freq[nextLargest - 'a']--;
                if (freq[nextLargest - 'a'] > 0) pq.add(nextLargest);
                pq.add(largest);
            }
        }

        return result.toString();
    }
}
