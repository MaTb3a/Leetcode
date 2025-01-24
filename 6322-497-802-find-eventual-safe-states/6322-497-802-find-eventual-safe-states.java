import java.util.*;

class Solution {
    public boolean dfs(int u, List<List<Integer>> graph, int[] state) {
        if (state[u] != 0) return state[u] == 1;
        state[u] = 2;
        for (int child : graph.get(u)) {
            if (!dfs(child, graph, state)) return false;
        }
        state[u] = 1;
        return true;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        int[] state = new int[n];
        List<Integer> ans = new ArrayList<>();
        List<List<Integer>> adjList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
            for (int neighbor : graph[i]) {
                adjList.get(i).add(neighbor);
            }
        }

        for (int i = 0; i < n; i++) {
            if (dfs(i, adjList, state)) ans.add(i);
        }
        return ans;
    }
}
