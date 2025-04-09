class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bitset<101>vis;
        for(auto it : nums)
            if(it < k)return -1;
            else if(it > k)vis[it] = 1;
        return vis.count();
    }
};