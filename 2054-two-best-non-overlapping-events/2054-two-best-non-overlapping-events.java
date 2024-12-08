import java.util.*;

class Solution {
    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, Comparator.comparingInt(a -> a[0])); // Sort by start time
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0])); // Min-heap: (end time, value)
        int maxValue = 0;
        int maxPrevValue = 0;

        for (int[] event : events) {
            int start = event[0], end = event[1], value = event[2];

            while (!pq.isEmpty() && pq.peek()[0] < start) {
                maxPrevValue = Math.max(maxPrevValue, pq.poll()[1]);
            }

            maxValue = Math.max(maxValue, value + maxPrevValue);

            pq.offer(new int[] { end, value });
        }

        return maxValue;
    }
}
