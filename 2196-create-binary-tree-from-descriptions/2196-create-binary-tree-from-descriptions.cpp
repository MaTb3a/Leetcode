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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_map<int,bool>vis;
        for(auto node : descriptions){
            int parent = node[0];
            int child = node[1];
            bool isLeft = node[2];
            vis[child] = true;
            if(!mp.count(parent))
                mp[parent] = new TreeNode(parent);
            if(!mp.count(child))
                mp[child] = new TreeNode(child);
            if(isLeft)
                mp[parent]->left = mp[child];
            else 
                mp[parent]->right = mp[child];
        }
        for(auto node : mp)
            if(!vis.count(node.first))
                return node.second;
        return NULL;

    }
};