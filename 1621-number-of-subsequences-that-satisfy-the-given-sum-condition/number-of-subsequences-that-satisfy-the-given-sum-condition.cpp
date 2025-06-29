class Solution {
public:
    int const mod = 1e9+7;
    long long fastPower(int b,int p){
        if(!p)return 1;
        long long ret = fastPower(b,p/2)%mod;
        if(p&1)return (ret * (ret * b)%mod)%mod;
        else return (ret * ret)%mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long cnt = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            auto it = upper_bound(nums.begin(),nums.end(),target-nums[i]) - nums.begin();
            if(it)--it;
            if(it >= i && nums[i] + nums[it] <= target){
                cnt += fastPower(2,it-i);
                cnt%=mod;
            }
        }
        return cnt;
    }
};