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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)return 0;
        int ret = ((root->val >= low && root->val <= high) ? root->val : 0);
        if(root->left)  ret +=rangeSumBST(root->left,low,high);
        if(root->right) ret+=rangeSumBST(root->right,low,high);
        return ret;
    }
};