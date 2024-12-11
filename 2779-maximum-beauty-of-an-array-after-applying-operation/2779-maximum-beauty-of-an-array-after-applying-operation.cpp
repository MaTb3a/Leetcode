class Solution {
public:
    
    int maximumBeauty(vector<int>& nums, int k) {
      

        int mx = *max_element(nums.begin(),nums.end());

        vector<int>vis(mx+1);
        int n = nums.size();
        for(int x : nums){
            vis[max(0,x-k)]++;
            vis[min(x+k+1,mx)]--;
        }
        int ans = 1,cnt = 0;
        for(int x : vis){
            cnt+=x;
            ans=max(ans,cnt);
        }
        return ans;

    }
};