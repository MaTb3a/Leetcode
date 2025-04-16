class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int,int>mp;
        for(int r = 0,l = 0; r < nums.size();r++){
            k-=mp[nums[r]]++;
            while(k <=0)k+=--mp[nums[l++]];
            ans+=l;
        }
        return ans;
    }
};