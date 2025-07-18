class Solution {
public:
    vector<long long>calcL(vector<int>& nums){
        int sz = nums.size(), n = sz/3;
        vector<long long>v(sz);
        priority_queue<int>pr;
        long long sum = 0;
        for(int i = 0 ; i < sz;i++){
            sum+=nums[i];
            pr.push(nums[i]);
            if(pr.size() > n){
                sum-=pr.top();pr.pop();
            }
            v[i] = sum;
        }
        return v;
    }
    vector<long long>calcR(vector<int>& nums){
        int sz = nums.size(), n = sz/3;
        vector<long long>v(sz);
        priority_queue<int>pr;
        long long sum = 0;
        for(int i = sz-1 ; i >= 0;i--){
            sum+=nums[i];
            pr.push(-nums[i]);
            if(pr.size() > n){
                sum-=-pr.top();pr.pop();
            }
            v[i] = sum;
        }
        return v;
    }
    long long minimumDifference(vector<int>& nums) {
       vector<long long>l = calcL(nums),r = calcR(nums);
       int sz = nums.size(),n = sz/3;
       long long ans = 1e18;
      
       for(int i = n ; i <= sz - n;i++){
        ans=min(ans,l[i-1]-r[i]);
       }
       return ans;
    }
};