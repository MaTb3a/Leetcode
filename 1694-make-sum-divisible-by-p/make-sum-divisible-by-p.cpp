class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<long long>pre(n+1);
        long long sum = 0;
        for(int i = 1 ; i <= n;i++){
            sum+=nums[i-1];
            pre[i] = pre[i-1]+nums[i-1];
        }
      
        int k = sum%p;

        if(!k)return 0;
      
            
       
        unordered_map<int,int>mp;
        
        mp[0] = 0;
        int ans = n;
        for(int i =1 ; i<= n;i++){
            int search = (pre[i] % p - k + p) % p;
            if(mp.count((search))){
                ans=min(ans,i-mp[search]);
            }
            mp[pre[i]%p] = i;

        }
        return ans == n ? -1 : ans;

    }
};