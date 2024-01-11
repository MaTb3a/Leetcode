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
    int solve(TreeNode* root,int mn,int mx){
        if(!root)return mx-mn;
        int ret= 0 ;
        if(root->left)
            ret=max(ret,solve(root->left,min(mn,root->val),max(mx,root->val)));
        if(root->right)
            ret=max(ret,solve(root->right,min(mn,root->val),max(mx,root->val)));
        mn = min(mn,root->val);
        mx = max(mx,root->val);
        return ret=max(ret,mx-mn);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root,1e9,0);
    }
};