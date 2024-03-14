class Solution {
public:
    int solve(vector<int>& nums, int goal){
        int i = 0 , j = 0 , ans = 0, sum = 0;
         while (i < nums.size()) {
            sum += nums[i];
            while (j <= i && sum > goal) {
                sum -= nums[j];
                j++;
            }
            ans += i - j + 1;
            i++;
        }
        return ans;
        
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal) - solve(nums,goal-1);
    }
};