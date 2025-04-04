/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var lcaDeepestLeaves = function(root) {
    function mxdepth(root) {
        if (!root) {
            return 0;
        }
        return Math.max(mxdepth(root.left), mxdepth(root.right)) + 1;
    }
    
    function dfs(root, d, mxd) {
        if (!root) {
            return null;
        }
        if (d === mxd) {
            return root;
        }
        
        const l = dfs(root.left, d + 1, mxd);
        const r = dfs(root.right, d + 1, mxd);
        
        if (l && r) {
            return root;
        }
        return l ? l : r;
    }
    
    return dfs(root, 1, mxdepth(root));
};