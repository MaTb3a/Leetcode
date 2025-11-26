class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pr;
        for(auto x : stones){
            pr.push(x);
        }
        while(pr.size()>1){
           int y = pr.top();pr.pop();
           int x = pr.top();pr.pop();
           pr.push(y-x);
        }
        return pr.top();
    }
};