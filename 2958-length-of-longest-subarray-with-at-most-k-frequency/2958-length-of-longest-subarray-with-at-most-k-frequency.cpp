class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int len = 0 , best = 0 , l = 0 ,r = 0;
        unordered_map<int,int>mp;
        while(true){
            if(mp[nums[r]]< k){
                mp[nums[r++]]++;
                len++;
                best=max(len,best);
                if(r==nums.size())break;
            }
            else {
               // if(l > r)break;
                mp[nums[l++]]--;
                len--;
            }
        }
        return best;
    }
};