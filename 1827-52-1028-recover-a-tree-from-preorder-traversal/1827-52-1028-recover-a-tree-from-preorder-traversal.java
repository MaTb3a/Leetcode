import java.util.Stack;

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
    public TreeNode recoverFromPreorder(String s) {
        Stack<TreeNode> stack = new Stack<>();
        int i = 0;
        while (i < s.length()) {
            int cnt = 0;
            while (i < s.length() && s.charAt(i) == '-') {
                cnt++;
                i++;
            }
            int v = 0;
            while (i < s.length() && Character.isDigit(s.charAt(i))) {
                v = v * 10 + (s.charAt(i) - '0');
                i++;
            }
            TreeNode node = new TreeNode(v);
            while (stack.size() > cnt) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                if (stack.peek().left == null) {
                    stack.peek().left = node;
                } else {
                    stack.peek().right = node;
                }
            }
            stack.push(node);
        }
        while (stack.size() > 1) {
            stack.pop();
        }
        return stack.pop();
    }
}