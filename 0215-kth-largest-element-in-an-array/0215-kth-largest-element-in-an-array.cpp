class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        multiset<int>mst;
        for(auto it : nums)mst.insert(-it);
     
        while(--k)mst.erase(mst.begin());
      
        return -*mst.begin();
    }
};