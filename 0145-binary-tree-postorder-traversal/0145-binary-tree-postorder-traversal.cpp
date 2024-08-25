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
    vector<int>v;
    void solve(TreeNode* root){
        // base 
        if(!root)return;
        solve(root->left);
        solve(root->right);
        v.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        solve(root);
        return v;
    }
};