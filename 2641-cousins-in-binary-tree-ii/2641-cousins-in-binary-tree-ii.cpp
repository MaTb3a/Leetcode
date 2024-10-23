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
    int sumByLevel[100000];
    void getSumLevel(TreeNode* root,int level){
        if(!root)return;
        sumByLevel[level]+=root->val;
        getSumLevel(root->left,level+1);
        getSumLevel(root->right,level+1);
    }
    void solve(TreeNode* root,int level,int sister){
         if(!root)return;
         
         root->val = sumByLevel[level] - root->val - sister;
         int leftSister = root->left ? root->left->val : 0;
         int rightSister = root->right ? root->right->val : 0;
            solve(root->left,level+1,rightSister);
            solve(root->right,level+1,leftSister);
         
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        getSumLevel(root,0);
        solve(root,0,0);
        return root;
    }
};