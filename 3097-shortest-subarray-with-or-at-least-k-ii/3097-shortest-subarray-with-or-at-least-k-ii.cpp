class Solution {
public:
    void update(int x,vector<int>&vis,int val){
        for(int i = 0 ; i < 32;i++)
            if((x>>i) &1)
                vis[i]+=val;
    }
    int getVal(vector<int>&vis){
        int x = 0;
         for(int i = 0 ; i < 32;i++)
            if(vis[i])
                x|=(1<<i);
        return x;
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int st = 0,ed = 0, cur = INT_MAX;
        vector<int>vis(32);
        while(true){
          if(getVal(vis) >= k && st < ed){
            cur = min(cur,ed-st);
            update(nums[st],vis,-1);
            st++;
          }
          else {
            if(ed == n)break;
             update(nums[ed++],vis,1);
          }
        }
        if(cur == INT_MAX)return -1;
        return cur;
    }
};