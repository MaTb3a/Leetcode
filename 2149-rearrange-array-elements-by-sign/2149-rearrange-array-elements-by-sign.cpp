class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>v(nums.size());
        int i = 0;
        for(auto t : nums)if(t>0)v[i]=t,i+=2;
        i = 1;
        for(auto t : nums)if(t<0)v[i]=t,i+=2;
        return v;
        
    }
};