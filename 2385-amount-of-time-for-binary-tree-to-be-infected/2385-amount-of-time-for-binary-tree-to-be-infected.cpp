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
    map<int,vector<int>>g;
    void solve(TreeNode* root){
        if(!root)return;
        if(root->left){
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
            solve(root->left);
        }
        if(root->right){
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
            solve(root->right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        int cnt = 0;
        solve(root);
        queue<int>q;
        q.push(start);
        unordered_map<int,bool>vis;
        vis[start]=1;
        while(q.size()){
            cnt++;
            int sz = q.size();
            while(sz--){
                int cur = q.front();q.pop();
                for(auto child : g[cur]){
                    if(!vis.count(child)){
                        vis[child]=1;
                        q.push(child);
                    }
                }
            }
        }
        return cnt-1;
    }
};