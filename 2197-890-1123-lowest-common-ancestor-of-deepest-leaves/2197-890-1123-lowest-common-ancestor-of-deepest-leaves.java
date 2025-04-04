/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return dfs(root, 1, maxDepth(root));
    }
    
    private int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }
    
    private TreeNode dfs(TreeNode root, int d, int maxD) {
        if (root == null) {
            return null;
        }
        if (d == maxD) {
            return root;
        }
        
        TreeNode l = dfs(root.left, d + 1, maxD);
        TreeNode r = dfs(root.right, d + 1, maxD);
        
        if (l != null && r != null) {
            return root;
        }
        return l != null ? l : r;
    }
}