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
    
    
    int dfs(TreeNode* root,int vis){
        if(!root)return 0;
        vis ^= (1 << root->val);
        if(!root->left and !root->right)
               return __builtin_popcount(vis) < 2;
        
        return dfs(root->left,vis)+dfs(root->right,vis);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root,0);
    }
};