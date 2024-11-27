import java.util.*;

class Solution {
    private List<List<Integer>> adj;

    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        // Initialize the adjacency list
        adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        // Add the default connections
        for (int i = 1; i < n; i++) {
            adj.get(i - 1).add(i);
        }

        // List to store the results
        List<Integer> result = new ArrayList<>();
        
        // Process each query
        for (int[] query : queries) {
            adj.get(query[0]).add(query[1]); // Add the new connection
            result.add(BFS(n));             // Find the shortest path using BFS
        }

        // Convert the result list to an int array
        int[] resultArray = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            resultArray[i] = result.get(i);
        }

        return resultArray;
    }

    // BFS function to calculate the shortest path
    private int BFS(int n) {
        Queue<Integer> queue = new LinkedList<>();
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        
        queue.add(0); // Start from city 0
        dist[0] = 0;

        while (!queue.isEmpty()) {
            int city = queue.poll();
            if (city == n - 1) { // Reached the destination
                return dist[city];
            }

            for (int neighbor : adj.get(city)) {
                if (dist[neighbor] > dist[city] + 1) {
                    dist[neighbor] = dist[city] + 1;
                    queue.add(neighbor);
                }
            }
        }

        return -1; // No path found
    }
}
