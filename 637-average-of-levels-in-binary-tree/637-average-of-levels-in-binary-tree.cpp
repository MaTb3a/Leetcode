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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        vector<double>ans;
        q.push(root);
        while(q.size()){
            double sum =0;
            int sz=q.size(),cnt=0;
            for(int i=0;i<sz;i++){
                TreeNode* cur = q.front();
                q.pop();
                if(!cur)continue;
                sum+=(cur->val);
                cnt++;
                if(cur->left);
                    q.push(cur->left);
                if(cur->right);
                    q.push(cur->right);
            }
            if(!cnt)break;
            ans.push_back(sum/cnt);
            
        }
        return ans;
    }
};