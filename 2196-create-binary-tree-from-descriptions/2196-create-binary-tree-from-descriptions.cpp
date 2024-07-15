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
       sort(descriptions.begin(),descriptions.end());
       int parent = -1;
       vector<pair<int,bool>>graph[100001];
       int vis[100001]={};
       for(auto node : descriptions){
            graph[node[0]].push_back({node[1],node[2]});
            vis[node[1]]++;
       }
        for(auto node : descriptions){
            if(!vis[node[0]]){
                parent = node[0];
                break;
            }
        }
        
       TreeNode* root = new TreeNode(parent);
       TreeNode* trace = root;
       queue<TreeNode*>q;
       q.push(trace);
       while(q.size()){
            int sz = q.size();
                auto cur = q.front();
                q.pop();
                cout<<q.size()<<endl;
                if(graph[cur->val].size() > 0){

                    if(graph[cur->val][0].second){
                        cur->left = new TreeNode(graph[cur->val][0].first);
                        q.push(cur->left);
                    }
                    else {

                        cur->right = new TreeNode(graph[cur->val][0].first);
                        q.push(cur->right);
                    }
                }
                if(graph[cur->val].size() > 1) {

                    if(graph[cur->val][1].second){

                        cur->left = new TreeNode(graph[cur->val][1].first);
                        q.push(cur->left);
                    }
                    else {

                        cur->right = new TreeNode(graph[cur->val][1].first);
                        q.push(cur->right);
                    }
                }
        
       }
       return root;
    }
};