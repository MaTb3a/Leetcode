import java.util.*;

class Solution {
    private int[] BobT;
    private int[] parent;

    private void BobDfs(int n, int p, List<List<Integer>> adj) {
        parent[n] = p;
        for (int ch : adj.get(n)) {
            if (ch == p) continue;
            BobDfs(ch, n, adj);
        }
    }

    private int AliceDfs(int n, int p, List<List<Integer>> adj, int AliceT, int[] amount) {
        int AliceM = 0;
        if (AliceT < BobT[n]) AliceM = amount[n];
        else if (AliceT == BobT[n]) AliceM = amount[n] / 2;

        if (adj.get(n).size() == 1 && n != 0) return AliceM;

        int mx = (int) -1e9;
        for (int ch : adj.get(n)) {
            if (ch == p) continue;
            mx = Math.max(mx, AliceDfs(ch, n, adj, AliceT + 1, amount));
        }
        return mx + AliceM;
    }

    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        int n = edges.length + 1;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int[] it : edges) {
            adj.get(it[0]).add(it[1]);
            adj.get(it[1]).add(it[0]);
        }

        BobT = new int[n];
        parent = new int[n];
        Arrays.fill(BobT, (int) 1e9);
        Arrays.fill(parent, (int) 1e9);
        BobDfs(0, -1, adj);

        int time = 0;
        for (int i = bob; i != -1; i = parent[i]) {
            BobT[i] = time++;
        }

        return AliceDfs(0, -1, adj, 0, amount);
    }
}