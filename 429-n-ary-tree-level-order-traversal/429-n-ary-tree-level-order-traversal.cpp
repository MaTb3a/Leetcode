/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node* >q;
        q.push(root);
        
        vector<vector<int>>ans;
        if(!root) return ans;

        while(q.size()){
            int sz=q.size();
            vector<int>v;
            
            while(sz--){
                auto cur = q.front();
                q.pop();

                v.push_back(cur->val);
                for(auto t : cur->children){
                    q.push(t);
                }
            }
            
            ans.push_back(v);
        }
        return ans;
    }
};