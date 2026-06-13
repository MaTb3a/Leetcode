class Solution {
public:
    int climbStairs(int n) {
        if(n<3)return n;
        int step1 = 1,step2 = 2,ans = step1+step2;
        for(int i = 3 ;i <=n;i++){
            ans = step1 + step2;
            step1 = step2;
            step2 = ans;
        }
        return ans;
    }
};