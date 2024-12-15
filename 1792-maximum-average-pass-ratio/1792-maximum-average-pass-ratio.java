import java.util.*;

class Solution {
    static class Ratio implements Comparable<Ratio> {
        int x, y;
        double gain;

        Ratio(int x, int y) {
            this.x = x;
            this.y = y;
            this.gain = (double) (x + 1) / (y + 1) - (double) x / y;
        }

        @Override
        public int compareTo(Ratio other) {
            return Double.compare(other.gain, this.gain);
        }
    }

    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<Ratio> pq = new PriorityQueue<>();
        for (int[] cls : classes) {
            pq.add(new Ratio(cls[0], cls[1]));
        }

        for (int i = 0; i < extraStudents; i++) {
            Ratio top = pq.poll();
            top.x++;
            top.y++;
            top.gain = (double) (top.x + 1) / (top.y + 1) - (double) top.x / top.y;
            pq.add(top);
        }

        double totalRatio = 0;
        while (!pq.isEmpty()) {
            Ratio top = pq.poll();
            totalRatio += (double) top.x / top.y;
        }

        return totalRatio / classes.length;
    }
}
