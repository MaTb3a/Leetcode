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
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return max (maxDepth(root->left), maxDepth(root->right))+1;
    }
    TreeNode* dfs(TreeNode* root,int d,int mxd){ // l r root
         if(!root)return nullptr;
         if(d == mxd)return root;
        auto l = dfs(root->left,d+1,mxd); // 7 
        auto r = dfs(root->right,d+1,mxd); // 4
        if(l && r)return root;
        return (l ? l  : r);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root,1,maxDepth(root));
    }
};