class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size(),ans = -1;
        int mp[82];
        for(auto x : nums){ 
            int tmp = x,sum = 0;
            while(tmp)sum+=tmp%10,tmp/=10; 
            if(!mp[sum])mp[sum] = x;
            else {
                ans=max(ans,mp[sum] + x);
                mp[sum] = max( mp[sum],x);
            }
        }
        return ans;
    }
};