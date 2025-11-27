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
    bool same(TreeNode* a, TreeNode* b){
        if(!a && !b)return true;
        if(!a || !b || (a->val != b->val))return false;
        return (same(a->left,b->left)) && (same(a->right,b->right));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(same(root,subRoot))return true;
        if(!root)return false;
        return isSubtree(root->left,subRoot) | isSubtree(root->right,subRoot);
    }
};