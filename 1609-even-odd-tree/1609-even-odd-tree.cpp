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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(q.size()){
            int sz = q.size();
            int lst =-1;
            while(sz--){
                auto cur = q.front();q.pop();
                if((level&1) == (cur->val &1))return false;
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
                if(lst != -1){
                    cout<<lst<<" "<<cur->val<<endl;
                    if(level&1 && lst <= cur->val)return false;
                    if( (level&1)== false && lst >= cur->val)return false;
                }
                lst = cur->val;       
            }
            level++;
        }
        return true;
    }
};