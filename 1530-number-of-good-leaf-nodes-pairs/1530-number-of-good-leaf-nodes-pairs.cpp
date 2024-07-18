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
    unordered_set<TreeNode*>leaves;
    unordered_map<TreeNode*, vector<TreeNode*>>graph;

    void dfs(TreeNode* root){
        if(!root)
            return;
        if(!root->left  && !root->right)
            leaves.insert(root);
        if(root->left){
            graph[root].push_back(root->left);
            graph[root->left].push_back(root);
        }

        if(root->right){
            graph[root].push_back(root->right);
            graph[root->right].push_back(root);
        }
        dfs(root->left);
        dfs(root->right);
    }  

    int BFS(TreeNode* src,int distance){
        queue<pair<TreeNode*,int>>q;
        unordered_set<TreeNode*>visit;
        q.push({src,0});
        visit.insert(src);
        int cnt = 0;
        while(q.size()){
            auto cur = q.front();
            q.pop();
            if(cur.first != src  && leaves.count(cur.first) && cur.second <= distance)
                cnt++;
            for(auto child : graph[cur.first]){
                if(!visit.count(child) && cur.second+1 <= distance ){
                    visit.insert(child);
                    q.push({child,cur.second+1});
                }
            }
        }
        return cnt;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root);
        int ans = 0;
        for(auto node : leaves){ //n^2
            ans+=BFS(node,distance);
        }

        return ans/2; // trick
    }
};