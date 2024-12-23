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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        int swp = 0;
        q.push(root);
        while(q.size()){
            int n = q.size();
            vector<int>v(n);
            for(int i = 0 ; i < n;i++){
                auto cur = q.front();q.pop();
                v[i] = (cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            vector<int>sorted=v;
            sort(sorted.begin(),sorted.end());
            unordered_map<int,int>mp;
            for(int i = 0 ; i < n;i++)mp[v[i]] = i;

            for(int i = 0 ; i < n;i++){
                if(v[i]!=sorted[i]){
                    int idx = mp[sorted[i]];
                    mp[v[i]] = idx;
                    swap(v[i],v[idx]);
                    swp++;
                }
            }
        }
        return swp;

    }
};