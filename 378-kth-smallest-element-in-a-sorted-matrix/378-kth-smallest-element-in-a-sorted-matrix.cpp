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
        //[[1,5,9],[10,11,13],[12,13,15]]
        // 1 5 9 10 11 12 13 13 
        
    }
};