import java.util.PriorityQueue;

class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        
        for (int num : nums) {
            pq.offer((long) num);
        }

        int cnt = 0;

        while (pq.size() > 1 && pq.peek() < k) {
            long x = pq.poll();
            long y = pq.poll();
            pq.offer(Math.min(x * 2 + y, (long) k + 1)); // Ensure long multiplication
            cnt++;
        }

        return cnt;
    }
}
