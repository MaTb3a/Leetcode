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
    map<int,pair<int,int>>mp;
    void dfs(TreeNode *root){
        if(!root)return;
        if(mp[root->val].first)
            root->left = new TreeNode(mp[root->val].first);
        if(mp[root->val].second)
            root->right = new TreeNode(mp[root->val].second);
        
        dfs(root->left);
        dfs(root->right);
    }   
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int arr[100005];
        iota(arr,arr+100005,0);
        
        for(auto x : descriptions){
            arr[x[1]] = x[0];

            if(!mp.count(x[0]))
                mp[x[0]] = {0,0};

            if(x[2])
                mp[x[0]].first = x[1];
            else mp[x[0]].second = x[1];
        }
        TreeNode *root;
        for(auto it : mp){
           // cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<"\n";
            if(arr[it.first] == it.first){
                root = new TreeNode(it.first);
               break;
            }
        }
        dfs(root);
        return root;
    }
};