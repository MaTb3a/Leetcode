class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>q;
        for(auto t : matrix)
            for(auto it : t){
                q.push(it);
                if(q.size()>k)
                    q.pop();
            }
        return q.top();
      
        
    }
};