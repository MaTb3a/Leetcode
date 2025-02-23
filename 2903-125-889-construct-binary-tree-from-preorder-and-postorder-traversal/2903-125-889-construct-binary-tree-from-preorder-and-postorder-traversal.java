class Solution {
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        Stack<TreeNode> stk = new Stack<>();
        TreeNode root = new TreeNode(preorder[0]);
        stk.push(root);
        int i = 1, j = 0;
        
        while (!stk.isEmpty()) {
            TreeNode cur = stk.peek();
            if (cur.val == postorder[j]) {
                stk.pop();
                j++;
                continue;
            }
            TreeNode node = new TreeNode(preorder[i++]);
            if (cur.left == null) cur.left = node;
            else cur.right = node;
            stk.push(node);
        }
        return root;
    }
}
