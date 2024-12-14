class Solution {
public:
    long long clac(int l,int r){
        long long n = r - l;
        return n*(n+1)/2;
    }
    long long continuousSubarrays(vector<int>& nums) {
        long long sum = 0;
        int l = 0 , r = 0 , n = nums.size();
        int mn = nums[0],mx=nums[0];
        while(r<n){
            mn = min(mn,nums[r]);
            mx = max(mx,nums[r]);
            if(mx - mn > 2){
                sum+=clac(l,r); // 3
                l = r;
                mn = mx = nums[r];
                while(l && abs(nums[r] - nums[l-1]) <= 2){
                    l--;
                    mn = min(mn,nums[l]);
                    mx = max(mx,nums[l]);
                }
                sum-=clac(l,r);
            }
            r++;
        }
        return sum+clac(l,r);
    }
};