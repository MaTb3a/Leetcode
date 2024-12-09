class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        for(int i = 1 ; i < n;i++) // n 
            if((nums[i]&1) ==  (nums[i-1]&1))
                nums[i-1] = 1;
            else 
                nums[i-1] = 0;

        for(int i = 1 ; i < n;i++)
            nums[i]+=nums[i-1];

        vector<bool>ans(queries.size(),true);

        for(int i = 0 ; i < queries.size();i++){ 
            int l = queries[i][0], r = queries[i][1];
            if(l == r)continue;
            int res = (r ? nums[r-1] : nums[r]) - (l ? nums[l-1] : 0 );
            ans[i] = res == 0;
        }
        return ans;
    }
};