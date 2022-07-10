class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>>pq;

        for (int i=n-1;i>=0;i--){
            while (pq.size() && pq.top().second-k > i)
                pq.pop();
            
                nums[i] = nums[i] + (pq.size()? pq.top().first:0);
           
                pq.push({nums[i],i});
            
            }
            return nums[0];
        }
    
};