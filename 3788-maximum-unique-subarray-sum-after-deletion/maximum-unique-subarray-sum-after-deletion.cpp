class Solution {
public:
    int maxSum(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end()),sum =0;
        bool ok = false;
        vector<bool>vis(101);
        for(int x : nums){
            if(x > 0 && !vis[x]){
                vis[x]=1;
                ok = true;
                sum+=x;
            }
        }
        return ok ? sum : mx;
    }
};