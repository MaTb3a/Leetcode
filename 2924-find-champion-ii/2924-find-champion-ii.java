import java.util.*;

class Solution {
    public int findChampion(int n, int[][] edges) {
        boolean[] visited = new boolean[n];
        for (int[] edge : edges) {
            visited[edge[1]] = true;
        }
        
        int champion = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (champion == -1) {
                    champion = i;
                } else {
                    return -1;
                }
            }
        }
        
        return champion;
    }
}
