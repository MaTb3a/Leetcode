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
    void dfs(TreeNode* root,int depth){
        if(root){
            if(v.size()==depth)
                v.push_back(root->val);
            dfs(root->right,depth+1);
            dfs(root->left,depth+1);
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        v.clear();
        dfs(root,0);
        return v;
    }
};