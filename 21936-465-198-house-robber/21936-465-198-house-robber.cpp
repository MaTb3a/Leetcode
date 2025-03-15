class Solution {
public:
    int solve(vector<int>& nums){
       int p1=0,p2=0;
       for(int x : nums){
        int mx = max(x+p2,p1);
        p2 = p1; p1 = mx;
       }
       return p1;
    }
    int rob(vector<int>& nums) {
        return solve(nums);
    }
};