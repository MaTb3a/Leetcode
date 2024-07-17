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
    bool deleted[1001];
    vector<TreeNode*> ans;
    TreeNode* dfs(TreeNode* root){
        if(!root)
            return nullptr;
        root->left = dfs(root->left);
        root->right = dfs(root->right);

        if(deleted[root->val]){
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);

            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int node : to_delete)
            deleted[node] = true;
        
        root = dfs(root);
        if(root)
            ans.push_back(root);
        return ans;
    }
};