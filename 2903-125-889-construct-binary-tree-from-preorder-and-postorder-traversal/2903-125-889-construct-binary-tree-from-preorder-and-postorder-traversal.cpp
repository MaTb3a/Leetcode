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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {//30
        stack<TreeNode*>stk;
        auto root = new TreeNode(preorder[0]);
        stk.push(root);
        int i = 1,j = 0;
        while(stk.size()){
            auto cur = stk.top(); //1
            if(cur->val == postorder[j]){
                stk.pop();j++;continue;
            }
            auto Node = new TreeNode(preorder[i++]); // 2
            if(!cur->left)cur->left = Node;
            else cur->right = Node;
            stk.push(Node);
        }
        return root;
    }
};