
class Solution {
    private Map<Integer, Deque<Integer>> adj = new HashMap<>();
    private LinkedList<Integer> path = new LinkedList<>();

    public int[][] validArrangement(int[][] pairs) {
        Map<Integer, Integer> inDegree = new HashMap<>();
        Map<Integer, Integer> outDegree = new HashMap<>();

        // Step 1: Build adjacency list and calculate in/out degrees
        for (int[] pair : pairs) {
            int u = pair[0], v = pair[1];
            adj.computeIfAbsent(u, k -> new ArrayDeque<>()).add(v);
            outDegree.put(u, outDegree.getOrDefault(u, 0) + 1);
            inDegree.put(v, inDegree.getOrDefault(v, 0) + 1);
        }

        // Step 2: Find the starting node for the Eulerian path
        int start = pairs[0][0];
        for (int node : outDegree.keySet()) {
            if (outDegree.getOrDefault(node, 0) - inDegree.getOrDefault(node, 0) == 1) {
                start = node;
                break;
            }
        }

        // Step 3: Perform Eulerian path using Hierholzer's algorithm
        euler(start);

        // Step 4: Build the result
        int[][] result = new int[pairs.length][2];
        int index = 0;
        Iterator<Integer> iterator = path.iterator();
        int prev = iterator.next();
        while (iterator.hasNext()) {
            int next = iterator.next();
            result[index][0] = prev;
            result[index][1] = next;
            prev = next;
            index++;
        }

        return result;
    }

    private void euler(int node) {
        Deque<Integer> stack = adj.getOrDefault(node, new ArrayDeque<>());
        while (!stack.isEmpty()) {
            int next = stack.poll();
            euler(next);
        }
        path.addFirst(node);
    }
}
