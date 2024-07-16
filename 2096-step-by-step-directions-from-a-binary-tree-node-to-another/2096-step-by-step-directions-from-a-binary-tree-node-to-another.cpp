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
    bool dfs(TreeNode* root,int node,string &path){
        if(!root)
            return false;
        if(root->val == node)
            return true;
        
        path+="L";
        if(dfs(root->left,node,path))
            return true;
        path.pop_back();

        path+="R";
        if(dfs(root->right,node,path))
            return true;
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path1 ,path2;
        dfs(root,startValue,path1);
        dfs(root,destValue,path2);
        int idx = 0;
        while(idx < path1.size() && idx < path2.size() && path1[idx] == path2[idx])
            idx++; // LCA

        int up = path1.size() - idx;
        return string(up,'U') + path2.substr(idx);
    }
};