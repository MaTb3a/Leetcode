/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    static int sumRootToLeaf(TreeNode*& root, int x=0) {
        if (!root) return 0;
        x=(x<<1)+root->val;
        if (!(root->left || root->right)) return x;
        return sumRootToLeaf(root->left, x)+sumRootToLeaf(root->right, x); 
    }
};