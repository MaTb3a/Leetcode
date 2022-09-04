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
    vector<vector<int>>v,ans;
    void dfs(TreeNode* root,int r,int c){
        if(!root)
            return;
        v.push_back({c,r,root->val});
        if(root->left)
            dfs(root->left,r+1,c-1);
        if(root->right)
            dfs(root->right,r+1,c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        sort(v.begin(),v.end());
        vector<int>tmp;
        int lst=1e9;
        for(auto t : v){
            if(lst==1e9)
                tmp.push_back(t[2]);
            else if(lst==t[0])
                tmp.push_back(t[2]);
            else {
                ans.push_back(tmp);
                tmp.clear();
                tmp.push_back(t[2]);
            }
            lst = t[0];
        }
        ans.push_back(tmp);

        return ans;
    }
};