class Solution {
public:
    vector<int>LIS(vector<int>& nums){
        int n = nums.size();
        vector<int>lis,idx(n,1);

        for(int i = 0 ; i < n;i++){
            auto it = lower_bound(lis.begin(),lis.end(),nums[i]);
            if(it == lis.end())
                lis.push_back(nums[i]);
            else *it = nums[i];

            idx[i] = lis.size();
        }
        return idx;
    }
    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size();
        vector<int>inc = LIS(nums);
        reverse(nums.begin(),nums.end());
        vector<int>dec = LIS(nums);
        reverse(dec.begin(),dec.end());

        
         int ans = n;

         for(int i = 0 ; i < n;i++){
            if(dec[i] > 1 && inc[i] > 1){
                int len = inc[i] + dec[i]-1;
                ans=min(ans,n-len);
            }
         }
         return ans;
        
    }

    //2,1,1,5,6,2,3,1
//    1 1 1 2 3 3 3 3

    // lis [1,2,3]
};