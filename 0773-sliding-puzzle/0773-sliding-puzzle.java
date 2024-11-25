
class Solution {
    private static final int[][] directions = {
        {1, 3},     // 0
        {0, 2, 4},  // 1
        {1, 5},     // 2
        {0, 4},     // 3
        {1, 3, 5},  // 4
        {2, 4}      // 5
    };

    public int slidingPuzzle(int[][] board) {
        StringBuilder sb = new StringBuilder();
        for (int[] row : board) {
            for (int cell : row) {
                sb.append(cell);
            }
        }
        String start = sb.toString();
        String target = "123450";

        Queue<Pair<Integer, String>> queue = new LinkedList<>();
        Map<String, Integer> visited = new HashMap<>();
        queue.add(new Pair<>(start.indexOf('0'), start));
        visited.put(start, 0);

        while (!queue.isEmpty()) {
            Pair<Integer, String> current = queue.poll();
            int zeroPos = current.getKey();
            String state = current.getValue();

            if (state.equals(target)) {
                return visited.get(state);
            }

            for (int neighbor : directions[zeroPos]) {
                char[] newState = state.toCharArray();
                char temp = newState[zeroPos];
                newState[zeroPos] = newState[neighbor];
                newState[neighbor] = temp;
                String newStateStr = new String(newState);

                if (!visited.containsKey(newStateStr)) {
                    visited.put(newStateStr, visited.get(state) + 1);
                    queue.add(new Pair<>(neighbor, newStateStr));
                }
            }
        }

        return -1;
    }

}
