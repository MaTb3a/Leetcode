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
    
    map<int,int>mp;
    int cnt=0;
    bool ok(){
        int ctr=0;
        for(auto t : mp){
            if(t.second&1)ctr++;
        }
        return ctr<2;
    }
    void dfs(TreeNode* root){
        if(!root)return ;
        if(!root->left and !root->right){
                mp[root->val]++;
                if(ok())cnt++;
                mp[root->val]--;
                return ;
        }
        mp[root->val]++;
        dfs(root->left);
        dfs(root->right);
        mp[root->val]--;

        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return cnt;
    }
};