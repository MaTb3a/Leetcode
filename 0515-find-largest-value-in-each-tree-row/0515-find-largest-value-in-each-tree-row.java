import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    // DFS Approach
    private void dfs(TreeNode root, int dep, List<Integer> ans) {
        if (root == null) return;
        if (ans.size() == dep) {
            ans.add(root.val);
        } else {
            ans.set(dep, Math.max(ans.get(dep), root.val));
        }
        dfs(root.left, dep + 1, ans);
        dfs(root.right, dep + 1, ans);
    }

    public List<Integer> largestValues(TreeNode root) {
        if (root == null) return new ArrayList<>();
        
        // BFS Approach
        Queue<TreeNode> q = new LinkedList<>();
        List<Integer> ans = new ArrayList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int sz = q.size();
            int mx = Integer.MIN_VALUE;
            for (int i = 0; i < sz; i++) {
                TreeNode node = q.poll();
                mx = Math.max(mx, node.val);
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
            ans.add(mx);
        }

        // Uncomment this for DFS:
        // List<Integer> dfsAns = new ArrayList<>();
        // dfs(root, 0, dfsAns);
        // return dfsAns;

        return ans;
    }
}
