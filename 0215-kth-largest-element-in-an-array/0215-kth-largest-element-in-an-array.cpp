class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pr;
        for(auto it : nums)pr.push(it);
        // 0 -1000 -10000 1 2 10000 20000  | k = 7
        
        //      -10000
        while(--k)pr.pop();// 0
        
        return pr.top();
    }
};