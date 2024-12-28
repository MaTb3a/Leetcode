class Solution {
public:
int dp[20002][4];
    int solve(int i,int rem,int k,vector<int>& nums){
        if(!rem)return 0;
        if(i >= nums.size())return -1e9;
        int &ret = dp[i][rem];
        if(~ret)return ret;
        ret = solve(i+1,rem,k,nums);
        if(i+k <= nums.size()){
            int sub = nums[i+k-1]  - (i > 0 ? nums[i-1] : 0);
            ret = max(ret,solve(i+k,rem-1,k,nums) + sub);
        }
        return ret;
    }
    vector<int>v;
    void print(int i,int rem,int k,vector<int>& nums){
        if(!rem)return ;
        if(i >= nums.size())return ;
        if( solve(i,rem,k,nums) == solve(i+k,rem-1,k,nums) +  nums[i+k-1]  - (i > 0 ? nums[i-1] : 0)){
            v.push_back(i);
            print(i+k,rem-1,k,nums);
        }
        else print(i+1,rem,k,nums);
    }

    bool path[20002][4];
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        for(int i = 1 ; i < nums.size() ; i++)nums[i]+=nums[i-1];
        int n = nums.size();
        memset(dp,-0x3f3f3f3f,sizeof dp);
        for(int i = 0 ; i <= n;i++)dp[i][0] = 0;

        for(int rem = 1 ; rem <=3 ; rem++){
            for(int i = n-1 ; i >=0 ;i--){
                dp[i][rem] = dp[i+1][rem];

                 if(i+k <= nums.size()){
                    int sub = nums[i+k-1]  - (i > 0 ? nums[i-1] : 0);
                    if(dp[i][rem]  <= dp[i+k][rem-1] + sub){
                        dp[i][rem]  = dp[i+k][rem-1] + sub;
                        path[i][rem] = true;
                    }
                }
            }
        }
        for(int i = 0,rem =3 ; i < n && rem ;i++)
            if(path[i][rem])v.push_back(i),rem--,i+=k-1;
      
        return v;
    }
};