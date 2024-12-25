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
    vector<int>ans;
    void dfs(TreeNode* root,int dep){
        if(!root)return;
        if(ans.size() == dep)ans.push_back(root->val);
        else ans[dep] = max(ans[dep],root->val);
        dfs(root->left,dep+1);
        dfs(root->right,dep+1);
    }
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);
        while(q.size()){
            int sz = q.size();//2
            int mx = INT_MIN; 
            while(sz--){
                auto node = q.front();q.pop();
                mx=max(mx,node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(mx);
        }
        return ans;
        
        // Solution #2
        dfs(root,0);
        return ans;
    }
};