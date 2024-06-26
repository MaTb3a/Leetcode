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
    void solve(TreeNode* node){
        if(!node)
            return;
        solve(node->left);
        v.push_back(node->val);
        solve(node->right);
    }
    TreeNode* BBST(int st,int ed){
        if(st > ed)
            return nullptr;
        int md = (st+ed)/2;
        TreeNode* node = new TreeNode(v[md]);
        node->left = BBST(st,md-1);
        node->right = BBST(md+1,ed);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
            solve(root);
            return BBST(0,v.size()-1);
    }
};