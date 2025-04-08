class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bitset<101>vis;
        for(int i = nums.size()-1 ; i>=0;i--)
            if(vis[nums[i]])return i/3+1;
            else vis[nums[i]] =1;
        return 0;
    }
};