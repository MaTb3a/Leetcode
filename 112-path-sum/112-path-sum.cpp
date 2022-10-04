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
    bool dfs(TreeNode* root,int targetSum){
        if(!root)
            return 0;
        if(root->right==nullptr and root->left==nullptr){
            return targetSum-root->val==0;
        }
        bool ok=0;
        ok|=dfs(root->left,targetSum-root->val);
        ok|=dfs(root->right,targetSum-root->val);
        return ok;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return !root ? 0 : dfs(root,targetSum);
    }
};